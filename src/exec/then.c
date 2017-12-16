/*
g** EPITECH PROJECT, 2017
** then.c
** File description:
** ; function
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

static void exec_process(list_t *list, list_t **l_env, int my_stdin,
			 int my_stdout)
{
	int pid;

	pid = fork();
	if (pid == -1)
		my_print_err("error fork");
	else if (pid == 0) {
		dup2(my_stdin, 0);
		dup2(my_stdout, 1);
		my_exec(((cmd_t *)list->data)->value, *l_env);
	} else {
		waitpid(pid, NULL, 0);
		command_handler(list->next->next, l_env, 0, 1);
	}
}

void then_handler(list_t *list, list_t **l_env, int my_stdin, int my_stdout)
{
	int pid;
	cmd_t *cmd_tmp = NULL;

	cmd_tmp = list->data;
	if (!builtins_handler(cmd_tmp, l_env, my_stdin, my_stdout)) {
		command_handler(list->next->next, l_env, 0, 1);
		return;
	}
	cmd_tmp->value[0] = get_access(cmd_tmp->value[0], *l_env);
	if (cmd_tmp->value[0] == NULL) {
		command_handler(list->next->next, l_env, 0, 1);
		return;
	}
	exec_process(list, l_env, my_stdin, my_stdout);
}
