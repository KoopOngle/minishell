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
	char **env = to_str_array(l_env);
	int i = 0;

	while (env[i]) 
		my_printf("%s\n", env[i++]);
	exit(1);
}
