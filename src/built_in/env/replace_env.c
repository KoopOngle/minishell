/*
** EPITECH PROJECT, 2017
** replace_env.c
** File description:
** Replace an env var by another
*/

#include <stdlib.h>
#include "list.h"
#include "env.h"
#include "string.h"

static int is_alpha_num(char c)
{
	return (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || is_digit(c));
}

static char *get_variable(list_t *l_env, char *new_env, int *i)
{
	char *backup = NULL;
	char *name = NULL;
	char *res = NULL;
	int in_brackets = 0;

	if (new_env[(*i) + 1] == '{')
		in_brackets = 1;
	cat_char(&backup, new_env[*i]);
	while (is_alpha_num(new_env[++(*i)])) {
		cat_char(&backup, new_env[*i]);
		cat_char(&name, new_env[*i]);
	}
	if (!in_brackets || (in_brackets && new_env[*i] == '}')) {
		res = get_env_value(l_env, name);
		free(name);
		free(backup);
		return (res);
	}
	free(name);
	return (backup);
}

char *cat_env_var(list_t *l_env, char *new_env)
{
	int i = 0;
	char *res = NULL;
	char *tmp = NULL;

	while (new_env[i]) {
		if (new_env[i] == '$') {
			tmp = get_variable(l_env, new_env, &i);
			cat(&res, tmp);
			if (tmp != NULL)
				free(tmp);
		} else
			cat_char(&res, new_env[i]);
		i++;
	}
	return (res);
}
