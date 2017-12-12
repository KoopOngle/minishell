/*
** EPITECH PROJECT, 2017
** read.c
** File description:
** read functions
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "error.h"
#include "my_printf.h"
#include "list.h"
#include "get_next_line.h"
#include "string.h"

int read_file(char *file_name)
{
	int fd;
	char *err = NULL;
	
	fd = open(file_name, O_RDONLY);
	if (fd == -1) {
		my_sprintf(&err, "Error: %s", file_name);
		my_print_err(err);
		free(err);
	}
	return (fd);
}

void read_stdin(char *word, int fd)
{
	list_t *l_str = NULL;
	list_t *l_tmp = NULL;
	char *tmp = get_next_line(0, '\n');

	while (compare(tmp, word)) {
		put_in_list(&l_str, tmp);
		tmp = get_next_line(0, '\n');
	}
	l_tmp = l_str;
	while (l_str) {
		tmp = l_str->data;
		my_dprintf(fd, "%s\n", tmp);
		l_tmp = l_str->next;
		free(tmp);
		free(l_str);
		l_str = l_tmp;
	}
}
