/*
** EPITECH PROJECT, 2017
** command_handler.c
** File description:
** Exec commands
*/

#include <stdlib.h>
#include <unistd.h>
#include "exec.h"
#include "string.h"
#include "my_printf.h"
#include "btree.h"
#include "error.h"

void command_handler(btree_t *cmd, list_t *l_env)
{
	int pid;
	
	if (cmd->is_separator) {
		my_printf("IS SEPARATOR\n");
		then(cmd, l_env, 0, 1);
	} else {
		pid = fork();
		switch (pid) {
		case -1:
			my_print_err("Error fork");
			break;
		case 0:
			my_exec(cmd->value, l_env);
			break;
		}
	}
}
