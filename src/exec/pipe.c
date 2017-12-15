/*
** EPITECH PROJECT, 2017
** pipe.c
** File description:
** | function
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
#include "string.h"
#include "get_next_line.h"
#include "parser.h"

void pipe_handler(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout)
{
	int pid_left = -1;
	int pid_right = -1;
	int fd[2];
	int nb_wait = 0;
	int pos;
	
	pipe(fd);
	if (btree->left->is_separator) {
		pos = pos_str_in_array((char **)EXEC, btree->left->value[0]);
		EXEC_FUNC[pos](btree->left, l_env, my_stdin, fd[1]);
	} else {
		nb_wait++;
		pid_left = fork();
		if (pid_left == -1)
			my_print_err("Error pipe fork");
		else if (pid_left == 0) {
			close(fd[0]);
			dup2(my_stdin, 0);
			dup2(fd[1], 1);
			close(fd[1]);
			my_exec(btree->left->value, l_env);
		}
	}
	if (btree->right->is_separator) {
		pos = pos_str_in_array((char **)EXEC, btree->right->value[0]);
		EXEC_FUNC[pos](btree->right, l_env, fd[0], my_stdout);
	} else {
		nb_wait++;
		pid_right = fork();
		if (pid_right == -1)
			my_print_err("Error pipe fork");
		else if (pid_right == 0) {
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
			my_exec(btree->right->value, l_env);
		} else {
			wait(NULL);
		}
	}
}
