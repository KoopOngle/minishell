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
#include "string.h"

void change_directory(list_t *l_env, char *str)
{
	char *str_err = NULL;
	int res;
	char *oldpwd = NULL;
	
	if (str == NULL)
		return;
	if (!compare(str, "-")) {
		oldpwd = get_env_value(l_env, "OLDPWD");
		if (oldpwd == NULL) {
			my_print_err("OLDPWD not set");
			free(str_err);
			return;
		}
		chdir(oldpwd);
	} else if (chdir(str) == -1) {
		my_sprintf(&str_err, "%s", str);
		my_print_err(str_err);
		free(str_err);
	}
}
