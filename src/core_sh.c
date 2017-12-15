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

static int is_redirection(cmd_t *cmd)
{
	return (!compare(cmd->value[0], ">") || !compare(cmd->value[0], ">>") ||
		!compare(cmd->value[0], "<") || !compare(cmd->value[0], "<<"));
}

static void change_path_cmd(list_t *list, list_t *l_env)
{
	cmd_t *cmd = NULL;
	
	if (list == NULL)
		return;
	cmd = list->data;
	if (cmd->is_separator) {
		if (list->next == NULL)
			return;
		if (is_redirection(cmd))
			change_path_cmd(list->next->next, l_env);
		else
			change_path_cmd(list->next, l_env);
	} else
		cmd->value[0] = get_access(cmd->value[0], l_env);
}

void core_sh(list_t *l_env)
{
	char *command = NULL;
	list_t *tmp = NULL;
	char **cmd = NULL;
	list_t *l_cmd = NULL;

	while (1) {
		my_printf("$>");
		command = get_next_line(0, '\n');
		if (command == 0)
			break;
		if (!compare(command, "")) {
			free(command);
			continue;
		}
		cmd = command_parser(command);
		l_cmd = create_cmd_list(cmd);
		change_path_cmd(l_cmd, l_env);
		tmp = l_cmd;
		cmd_t *lala = NULL;
		while (tmp) {
			lala = tmp->data;
			my_printf("%s\n", lala->value[0]);
			tmp = tmp->next;
		}
		command_handler(l_cmd, l_env);
		free(cmd); // free dedans
		free(l_cmd);
	}
}
