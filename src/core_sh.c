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

static void change_path_cmd(btree_t *btree, list_t *l_env)
{
	if (btree == NULL)
		return;
	if (btree->is_separator) {
		if (btree->value[0][0] == '|' || btree->value[0][0] == ';') {
			change_path_cmd(btree->left, l_env);
			change_path_cmd(btree->right, l_env);
		} else 
			change_path_cmd(btree->left, l_env);
	} else {
		btree->value[0] = get_access(btree->value[0], l_env);
	}
}

void core_sh(list_t *l_env)
{
	char *command = NULL;
	list_t *tmp = l_env;
	char **cmd = NULL;
	btree_t *btree = NULL;

	while (1) {
		my_printf("enter your command$>");
		command = get_next_line(0, '\n');
		if (!compare(command, "")) {
			free(command);
			continue;
		}
		cmd = command_parser(command);
		btree = create_btree(cmd);
		change_path_cmd(btree, l_env);
		command_handler(btree, l_env);
		free(cmd); // free dedans
		free(btree);
	}
}
