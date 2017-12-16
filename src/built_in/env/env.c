/*
** EPITECH PROJECT, 2017
** env.c
** File description:
** function env
*/

#include <stdlib.h>
#include "env.h"
#include "my_printf.h"

void env(list_t *l_env)
{
	char **env = NULL;
	int i = 0;

	if (l_env == NULL)
		return;
	env  = to_str_array(l_env);
	while (env[i]) 
		my_printf("%s\n", env[i++]);
}
