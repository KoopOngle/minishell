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
#include "btree.h"
#include "error.h"
#include "parser.h"

void command_handler(btree_t *cmd, list_t *l_env)
{
	int pid;
	int pos;
	
	if (cmd->is_separator) {
		pos = pos_str_in_array((char **)EXEC, cmd->value[0]);
		EXEC_FUNC[pos](cmd, l_env, 0, 1);
	} else {
		pid = fork();
		switch (pid) {
		case -1:
			my_print_err("Error fork");
			break;
		case 0:
			my_exec(cmd->value, l_env);
			break;
		default:
			waitpid(pid, NULL, 0);
		}
	}
}
