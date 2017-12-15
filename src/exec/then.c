/*
** EPITECH PROJECT, 2017
** then.c
** File description:
** ; function
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
#include "parser.h"

static void handle_cmd(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout)
{
	int pid;
	int fd[2];
	int pos;
	
	if (btree->is_separator) {
		pos = pos_str_in_array((char **)EXEC, btree->value[0]);
		EXEC_FUNC[pos](btree, l_env, 0, 1);
	} else {
		pipe(fd);
		pid = fork();
		if (pid == -1)
			my_print_err("Error fork");
		else if (pid == 0) {
			dup2(fd[0], my_stdin);
			my_exec(btree->value, l_env);
		} else
			wait(NULL);
	}
}

void then_handler(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout)
{
	handle_cmd(btree->left, l_env, my_stdin, my_stdout);
	handle_cmd(btree->right, l_env, my_stdin, my_stdout);
}
