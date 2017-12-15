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

void stdin_handler(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout)
{
       	int pid;

	pid = fork();
	if (pid == -1)
		my_print_err("error fork");
	else if (pid == 0) {
		read_stdin(btree->right->value[0], 0);
//		dup2(my_stdin, 0);
		my_exec(btree->left->value, l_env);
	}
	wait(NULL);
}
