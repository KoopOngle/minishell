/*
** EPITECH PROJECT, 2017
** core.c
** File description:
** Core of the minishell
*/

#include <stdlib.h>
#include <sys/wait.h>
#include "get_next_line.h"
#include "list.h"
#include "my_printf.h"
#include "parser.h"
#include "env.h"
#include "exec.h"
#include "string.h"

static int is_redirection(cmd_t *cmd)
{
	return (!compare(cmd->value[0], ">") || !compare(cmd->value[0], ">>") ||
		!compare(cmd->value[0], "<") || !compare(cmd->value[0], "<<"));
}

static int nb_redirection(list_t *list)
{
	cmd_t *cmd = NULL;
	list_t *tmp = list;
	int size = 0;

	while (tmp) {
		cmd = tmp->data;
		if (cmd->value[0] == NULL)
			return (-1);
		size += is_redirection(cmd);
		tmp = tmp->next;
	}
	return (size);
}

static void wait_all(list_t *l_cmd)
{
	int size;

	if (nb_redirection(l_cmd) == -1)
		return;
	size = list_size(l_cmd) - nb_redirection(l_cmd);
	if (size == 1)
		wait(NULL);
	else
		for (int i = 0; i < size / 2 + 1; i++)
			wait(NULL);
}

static void free_all(list_t *l_cmd)
{
	list_t *next = NULL;
	cmd_t *cmd = NULL;
	int i;

	if (l_cmd == NULL)
		return;
	while (l_cmd) {
		cmd = l_cmd->data;
		i = 0;
		while (cmd->value[i])
			free(cmd->value[i++]);
		free(cmd);
		next = l_cmd->next;
		free(l_cmd);
		l_cmd = next;
	}
}

void core_sh(list_t *l_env)
{
	char *command = NULL;
	char **cmd = NULL;
	list_t *l_cmd = NULL;

	while (1) {
		command = get_next_line(0, '\n');
		if (command == 0)
			break;
		if (!compare(command, "")) {
			free(command);
			continue;
		}
		cmd = command_parser(command);
		l_cmd = create_cmd_list(cmd);
		command_handler(l_cmd, &l_env, 0, 1);
		wait_all(l_cmd);
		free_all(l_cmd);
	}
}
