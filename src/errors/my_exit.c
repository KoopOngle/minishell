/*
** EPITECH PROJECT, 2017
** my_exit.c
** File description:
** my exit
*/

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "my_printf.h"

void my_print_err(char *str)
{
	perror(str);
}

void my_exit(char *str, int err_value)
{
	perror(str);
	exit(err_value);
}
