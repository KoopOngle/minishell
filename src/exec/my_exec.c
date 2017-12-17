/*
** EPITECH PROJECT, 2017
** my_exec.c
** File description:
** Function that exec a programm
*/

#include <stdlib.h>
#include <unistd.h>
#include "env.h"
#include "error.h"

void my_exec(char **argv, list_t *l_env)
{
	char **env = to_str_array(l_env);

	if (!argv || !argv[0])
		exit(84);
	execve(argv[0], argv, env);
	my_print_err("error after exec");
	exit(84);
}
