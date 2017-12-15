/*
** EPITECH PROJECT, 2017
** out.c
** File description:
** > function
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

void out_handler(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout)
{
	int fd = write_file(btree->right->value[0]);
	int pid;

	if (fd < 0)
		my_print_err("error opening file");
	pid = fork();
	if (pid == -1)
		my_print_err("error fork");
	else if (pid == 0) {
		dup2(fd, 1);
		my_exec(btree->left->value, l_env);
	}
	wait(NULL);
}
