/*
** EPITECH PROJECT, 2017
** set_env.c
** File description:
** Set an env variable
*/

#include <stdlib.h>
#include "list.h"
#include "env.h"
#include "string.h"
#include "memory.h"

static void replace_env(list_t *l_env, env_var_t *env, char *new_value)
{	
	new_value = cat_env_var(l_env, new_value);
	env->value = new_value;
}

static void add_to_env(list_t **l_env, char *name, char *value)
{
	env_var_t *env = NULL;

	if (name == NULL)
		return;
	env = my_calloc(sizeof(env_var_t));
	env->name = name;
	env->value = cat_env_var(*l_env, value);
	put_in_list(l_env, env);
}

void set_env(list_t *l_env, char *name, char *value)
{
	list_t *tmp_l = l_env;
	env_var_t *tmp_env = NULL;
	int stop = 0;
	
	if (name == NULL) {
		env(l_env);
		return;
	}
	while (tmp_l && !stop) {
		tmp_env = tmp_l->data;
		if (!compare(tmp_env->name, name))
			stop = 1;
		else
			tmp_l = tmp_l->next;
	}
	if (stop)
		replace_env(l_env, tmp_env, value);
	else
		add_to_env(&l_env, name, value);
}
