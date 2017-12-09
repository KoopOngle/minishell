/*
** EPITECH PROJECT, 2017
** get_env.c
** File description:
** Function used to get all of the env variables
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "my_printf.h"

static void exec_env()
{
	char *argv[] = {"/usr/bin/env"};
	char *env_arg[] = {NULL};

	execve("/usr/bin/env", argv, env_arg);
}

char **get_env()
{
	int fd[2];
	int pid;
	char **res = NULL;

	pipe(fd);
	pid = fork();
	switch() {
	case -1:
		my_dprintf(2, "Error getting the env variables.\n");
		exit(84);
		break;
	case 0:
		close(fd[1]);
		dup2(fd[0], 0);
		exec_env();
		break;
	default:
		close(fd[0]);
		res = get_line_in_file(fd[1]);
	}
	return (res);
}
