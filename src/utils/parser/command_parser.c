/*
** EPITECH PROJECT, 2017
** command_parser.c
** File description:
** Parse the command entered by the user
*/

#include <stdlib.h>
#include "my_printf.h"
#include "string.h"
#include "parser.h"

static int is_separator(char c)
{
	switch (c) {
	case ' ':
	case '\t':
	case '|':
	case '>':
	case '<':
	case ';':
		return (1);
	default:
		return (0);
	}
}

static void handle_separator(char **res, char *cmd, int *i)
{
	if (cmd[*i] == ' ' || cmd[*i] == '\t') {
		if (*i > 0 && cmd[(*i) - 1] != ' ' && cmd[(*i) - 1] != '\t')
			cat_char(res, ' ');
	} else if (cmd[*i] == '|' || cmd[*i] == ';') {
		if (*i > 0 && cmd[(*i) - 1] != ' ' && cmd[(*i) - 1] != '\t')
			cat_char(res, ' ');
		cat_char(res, cmd[*i]);
	} else {
		if (*i > 0 && cmd[(*i) - 1] != ' ' && cmd[(*i) - 1] != '\t')
			cat_char(res, ' ');
		cat_char(res, cmd[*i]);
		if (cmd[(*i) + 1] == cmd[(*i)])
			cat_char(res, cmd[(*i)++]);
	}
	(*i)++;
}

static void handle_normal(char **res, char *cmd, int *i)
{
	int begin = *i;

	if ((*i) && cmd[(*i) - 1] != ' ')
		cat_char(res, ' ');
	while (cmd[*i] && !is_separator(cmd[*i]) && cmd[*i] != '\n')
		(*i)++;
	ncat(res, cmd + begin, *i - begin);
}

static char *parse_spaces(char *command)
{
	char *res = NULL;
	int i = 0;
	int end;
	int begin = i;

	while (command[i])
		if (is_separator(command[i]))
			handle_separator(&res, command, &i);
		else
			handle_normal(&res, command, &i);
	i = 0;
	while (res[i])
		i++;
	if (res[i - 1] == ' ')
		res[i - 1] = 0;
	return (res);
}

char **command_parser(char *command)
{
	char **res = NULL;

	if (command == NULL)
		return (NULL);
	command = parse_spaces(command);
	res = my_str_to_word_array(command);
	return (res);
}
