/*
** EPITECH PROJECT, 2017
** command_handler.c
** File description:
** Exec commands
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "exec.h"
#include "string.h"
#include "my_printf.h"
#include "error.h"
#include "parser.h"
#include "list.h"

static void child_process(char **values, list_t *l_env, int my_stdin,
			  int my_stdout)
{
	int pid;

	pid = fork();
	if (pid == -1)
		my_print_err("Error fork");
	else if (pid == 0) {
		dup2(my_stdin, 0);
		dup2(my_stdout, 1);
		my_exec(values, l_env);
	}
}

void command_handler(list_t *cmd, list_t **l_env, int my_stdin, int my_stdout)
{
	int pid;
	int pos;
	cmd_t *cmd_tmp = NULL;

	if (cmd->next == NULL) {
		cmd_tmp = cmd->data;
		if (!builtins_handler(cmd_tmp, l_env, my_stdin, my_stdout))
			return;
		cmd_tmp->value[0] = get_access(cmd_tmp->value[0], *l_env);
		if (!cmd_tmp || !cmd_tmp->value[0])
			return;
		child_process(((cmd_t *)cmd->data)->value, *l_env, my_stdin,
			      my_stdout);
	} else {
		pos = pos_str_in_array((char **)EXEC,
				       ((cmd_t *)cmd->next->data)->value[0]);
		EXEC_FUNC[pos](cmd, l_env, my_stdin, my_stdout);
	}
}
