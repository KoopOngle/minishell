/*
** EPITECH PROJECT, 2017
** cd.c
** File description:
** Function used to change directory
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_printf.h"
#include "error.h"

int change_directory(char *str)
{
	char *str_err = NULL;
	int res;


	if (chdir(str) == -1) {
		my_sprintf(&str_err, "cd : %s", str);
		my_print_err(str_err);
		free(str_err);
		return (1);
	}
	return (0);
}
