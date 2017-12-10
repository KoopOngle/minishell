/*
** EPITECH PROJECT, 2017
** get_env_value.c
** File description:
** Return the env value of a var
*/

#include <stdlib.h>
#include "list.h"
#include "env.h"
#include "string.h"

char *get_env_value(list_t *l_env, char *name)
{
	list_t *tmp_list = NULL;
	env_var_t *tmp_env = NULL;
	int stop = 0;

	if (l_env == NULL || name == NULL)
		return (NULL);
	tmp_list = l_env;
	while (tmp_list && !stop) {
		tmp_env = tmp_list->data;
		if (!compare(tmp_env->name, name))
			stop = 1;
		else
			tmp_list = tmp_list->next;
	}
	if (tmp_list)
		return (tmp_env->value);
	return (NULL);
}
