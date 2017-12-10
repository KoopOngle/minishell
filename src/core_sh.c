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

void core_sh(list_t *env)
{
	char *command = NULL;

	my_printf("ici\n");
	while (1) {
		command = get_next_line(0, '\n');
		my_printf("command : %s\n", command);
		// send pour get en btree
		// exec du btree
	}
}
