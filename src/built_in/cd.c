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
#include "env.h"

void change_directory(char *str)
{
	char *str_err = NULL;
	int res;

	if (str == NULL)
		return;
	if (chdir(str) == -1) {
		my_sprintf(&str_err, "%s", str);
		my_print_err(str_err);
		free(str_err);
	}
}
