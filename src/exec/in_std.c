/*
** EPITECH PROJECT, 2017
** in_std.c
** File description:
** << function
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "btree.h"
#include "my_printf.h"
#include "list.h"
#include "exec.h"
#include "error.h"

void stdin_handler(list_t *list, list_t *l_env, int *my_stdin, int *my_stdout)
{
	int fd[2];
	int pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		my_print_err("error fork");
	else if (pid == 0) {
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		read_stdin(((cmd_t *)list->data)->value[0], *my_stdin);
		exit(0);
	} else {
		close(fd[1]);
		*my_stdin = fd[0];
		waitpid(pid, NULL, 0);
	}
}
