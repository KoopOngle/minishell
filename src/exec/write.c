/*
** EPITECH PROJECT, 2017
** write.c
** File description:
** Function used to write in a file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "error.h"
#include "my_printf.h"

int write_file(char *file_name)
{
	int fd;
	int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	char *err = NULL;
	
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (fd == -1) {
		my_sprintf(&err, "Error: %s", file_name);
		my_print_err(err);
		free(err);
	}
	return (fd);
}

int append_file(char *file_name)
{
	int fd;
	int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	fd = open(file_name, O_APPEND | O_CREAT | O_WRONLY, mode);
	if (fd == -1)
		my_print_err("Error open");
	return (fd);
}
