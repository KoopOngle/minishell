/*
** EPITECH PROJECT, 2017
** then.c
** File description:
** ; function
*/

#include <stdlib.h>
#include <unistd.h>
#include "btree.h"
#include "my_printf.h"
#include "list.h"
#include "exec.h"

int then(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout)
{
	int pid;
	
	if (btree->left->is_separator) {
		my_printf("LEFT IS SEPARATOR\n");
	} else {
		pid = fork();
		if (pid == 0) {
			my_printf("name left : %s\n", btree->left->value[0]);
			my_exec(btree->left->value, l_env);
		}
	}
	if (btree->right->is_separator) {
		my_printf("RIGHT IS SEPARATOR\n");
	} else {
		pid = fork();
		if (pid == 0) {
			my_printf("name right : %s\n", btree->right->value[0]);
			my_exec(btree->right->value, l_env);
		}
	}
}
