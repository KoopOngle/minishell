/*
** EPITECH PROJECT, 2017
** init_sh.c
** File description:
** Init function
*/

#include <stdlib.h>
#include "list.h"
#include "env.h"
#include "memory.h"
#include "string.h"

static int get_pos_first_equal(char *str)
{
	int i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

static void add_to_list(list_t **l_env, char *new_env)
{
	int pos_equal;
	env_var_t *env_var = NULL;
	
	if (new_env == NULL)
		return;
	pos_equal = get_pos_first_equal(new_env);
	if (pos_equal == -1)
		return;
	env_var = my_calloc(sizeof(env_var_t));
	ncat(&(env_var->name), new_env, pos_equal);
	cat(&(env_var->value), new_env + pos_equal + 1);
	put_in_list(l_env, env_var);
}

list_t *init_sh(char **env)
{
	int i = 0;
	list_t *l_env = NULL;
	
	if (env == NULL || env[0] == NULL)
		return (NULL);	
	while (env[i]) {
		add_to_list(&l_env, env[i]);
		i++;
	}
	return (l_env);
}
