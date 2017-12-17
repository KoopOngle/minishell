/*
** EPITECH PROJECT, 2017
** in.c
** File description:
** < function
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my_printf.h"
#include "list.h"
#include "exec.h"
#include "error.h"

void in_handler(list_t *list, list_t *l_env, int *my_stdin, int *my_stdout)
{
	int fd = read_file(((cmd_t *)list->data)->value[0]);

	*my_stdin = fd;
}
