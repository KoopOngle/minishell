/*
** EPITECH PROJECT, 2017
** get_env.c
** File description:
** Function used to get all of the env variables
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "my_printf.h"

static int open_env()
{
	int pid = getpid();
	char *path = NULL;
	int fd;

	my_sprintf(&path, "/proc/%d/environ", pid);
	fd = open(path, O_RDONLY);
	free(path);
	return (fd);
}

char **get_env()
{
	char **res = NULL;
	int fd = open_env();

	if (fd < 0)
		return (NULL);
	res = get_file_in_line(fd, '\0');
       	return (res);
}
