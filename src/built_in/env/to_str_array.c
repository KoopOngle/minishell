/*
** EPITECH PROJECT, 2017
** to_str_array.c
** File description:
** return an array of string of the env variables
*/

#include <stdlib.h>
#include "list.h"
#include "env.h"
#include "my_printf.h"
#include "memory.h"

char **to_str_array(list_t *l_env)
{
	int size;
	char **res = NULL;
	env_var_t *tmp = NULL;
	list_t *tmp_list = l_env;
	char *tmp_str = NULL;
	int i = 0;
		
	if (l_env == NULL)
		return (NULL);
	size = list_size(l_env);
	res = my_calloc(sizeof(char *) * (size + 1));
	while (tmp_list) {
		tmp = tmp_list->data;
		my_sprintf(&tmp_str, "%s=%s", tmp->name, tmp->value);
		res[i++] = tmp_str;
		tmp_str = NULL;
		tmp_list = tmp_list->next;
	}
	return (res);
}
