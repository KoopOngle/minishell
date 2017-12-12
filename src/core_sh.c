/*
** EPITECH PROJECT, 2017
** core.c
** File description:
** Core of the minishell
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "list.h"
#include "my_printf.h"
#include "parser.h"
#include "env.h"
#include "exec.h"
#include "btree.h"
#include "string.h"

void core_sh(list_t *l_env)
{
	char *command = NULL;
	list_t *tmp = l_env;
	char **cmd = NULL;
	btree_t *btree = NULL;
	
	while (1) {
		command = get_next_line(0, '\n');
		if (!compare(command, "")) {
			free(command);
			continue;
		}
		cmd = command_parser(command);
		btree = create_btree(cmd);
		command_handler(btree, l_env);
		free(cmd); // free dedans
		free(btree);
	}
}
