/*
** EPITECH PROJECT, 2017
** unset_env.c
** File description:
** delete the environment variable
*/

#include <stdlib.h>
#include "env.h"
#include "list.h"

void unset_env(list_t **l_env, char *name)
{
	delete_node(l_env, get_node_by_name(l_env, name));
}
