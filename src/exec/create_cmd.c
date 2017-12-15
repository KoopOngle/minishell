/*
** EPITECH PROJECT, 2017
** create_cmd.c
** File description:
** create a structure cmd
*/

#include <stdlib.h>
#include "exec.h"
#include "string.h"


static int get_prio(char *str)
{
        if (compare(str, ";") == 0)
                return (2);
	else if (compare(str, "|") == 0 || compare(str, "<<") == 0 ||
                 compare(str, ">") == 0 || compare(str, ">>") == 0 ||
                 compare(str, "<") == 0)
                return (1);
        else
                return (0);
}

cmd_t *create_cmd(char **value)
{
	cmd_t *cmd = malloc(sizeof(cmd_t));

	cmd->value = value;
	cmd->is_separator = (value && get_prio(value[0]));
	return (cmd);
}
