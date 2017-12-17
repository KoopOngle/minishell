/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main of the minishell 3
*/

#include <stdlib.h>
#include "my_sh.h"
#include "my_printf.h"
#include "env.h"
#include "list.h"

int main(int argc, char **argv, char **env)
{
	list_t *l_env = NULL;

	l_env = init_sh(env);
	core_sh(l_env);
	return (0);
}
