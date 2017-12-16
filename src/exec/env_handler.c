/*
** EPITECH PROJECT, 2017
** env_handler.c
** File description:
** handle the builtins
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
#include "env.h"

static void exec_builtin(int pos, cmd_t *cmd, list_t **l_env)
{
	switch (pos) {
	case 0:
		if (cmd->value[1])
			change_directory(cmd->value[1]);
		break;
	case 1:
		env(*l_env);
		break;
	case 2:
		if (cmd->value[1])
			set_env(*l_env, cmd->value[1], cmd->value[2]);
		break;
	case 3:
		if (cmd->value[1])
			unset_env(l_env, cmd->value[1]);
		break;
	case 4:
		my_exit();
		break;
	}
}

int builtins_handler(cmd_t *cmd, list_t **l_env, int my_stdin, int my_stdout)
{
	int pos;
	int pid;

	pos = pos_str_in_array((char **)BUILTINS, cmd->value[0]);
	if (pos == -1)
		return (1);
	dup2(my_stdin, 0);
	dup2(my_stdout, 1);
	exec_builtin(pos, cmd, l_env);
	return (0);
}
