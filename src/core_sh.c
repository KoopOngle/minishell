/*
** EPITECH PROJECT, 2017
** core.c
** File description:
** Core of the minishell
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "list.h"
#include "my_printf.h"
#include "env.h"

void core_sh(list_t *env)
{
	char *command = NULL;
	list_t *tmp = env;
	
	while(tmp) {
		my_printf("NAME : %s | VALUE : %s\n", ((env_var_t *)tmp->data)->name, ((env_var_t *)tmp->data)->value);
		tmp = tmp->next;
	}
	
	while (1) {
		command = get_next_line(0, '\n');
		my_printf("command : %s\n", command);
		// send pour get en btree
		// exec du btree
	}
}
