/*
** EPITECH PROJECT, 2017
** redirection.c
** File description:
** handle redirections
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "btree.h"
#include "my_printf.h"
#include "list.h"
#include "exec.h"
#include "error.h"
#include "parser.h"
#include "string.h"

static int is_redirection(cmd_t *cmd)
{
	return (!compare(cmd->value[0], ">") || !compare(cmd->value[0], ">>") ||
		!compare(cmd->value[0], "<") || !compare(cmd->value[0], "<<"));
}

static void child_process(list_t *list, list_t **l_env, int my_stdin,
			 int my_stdout)
{
	list_t *cursor = list->next;
	cmd_t *cmd = cursor->data;
	int pos = -1;

	while (cursor && cmd->is_separator && is_redirection(cmd)) {
		pos = pos_str_in_array((char **)REDIRECT, cmd->value[0]);
		cursor = cursor->next;
		REDIRECT_FUNC[pos](cursor, *l_env,
				   &my_stdin, &my_stdout);
		cursor = cursor->next;
		if (cursor)
			cmd = cursor->data;
	}
	dup2(my_stdin, 0);
	dup2(my_stdout, 1);
	my_exec(((cmd_t *)list->data)->value, *l_env);
}

static void main_process(list_t *list, list_t **l_env, int my_stdin,
			 int my_stdout)
{
	list_t *cursor = list->next;
	cmd_t *cmd = cursor->data;

	while (cursor && cmd->is_separator && is_redirection(cmd)) {
		cursor = cursor->next->next;
		if (cursor)
			cmd = cursor->data;
	}
	if (cursor)
		cursor = cursor->next;
	waitpid(-1, NULL, 0);
	if (cursor)
		command_handler(cursor, l_env, 0, 1);
}

void redirect_handler(list_t *list, list_t **l_env, int my_stdin,
			 int my_stdout)
{
	int pid;
	cmd_t *cmd_tmp = NULL;

	cmd_tmp = list->data;
	if (!builtins_handler(cmd_tmp, l_env, my_stdin, my_stdout))
		return;
	cmd_tmp->value[0] = get_access(cmd_tmp->value[0], *l_env);
	if (cmd_tmp->value[0] == NULL) {
		command_handler(list->next->next, l_env, 0, 1);
		return;
	}
	pid = fork();
	if (pid == -1)
		my_print_err("Error pipe fork");
	else if (pid == 0) {
		child_process(list, l_env, my_stdin, my_stdout);
	} else
		main_process(list, l_env, my_stdin, my_stdout);
}
