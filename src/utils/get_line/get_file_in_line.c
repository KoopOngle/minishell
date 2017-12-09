/*
** EPITECH PROJECT, 2017
** get_file_in_line.c
** File description:
** Return the file stocked in line
*/

#include <stdlib.h>
#include "get_next_line.h"

static char **rea_and_add(char **str, char *buffer, int size)
{
	char **new_str = malloc(sizeof(char *) * size);

	if (new_str == NULL)
		return (NULL);
	for (int i = 0; i < size - 1; i++)
		new_str[i] = str[i];
	new_str[size - 1] = buffer;
	if (str != NULL)
		free(str);
	str = new_str;
	return (new_str);
}

char **get_file_in_line(int fd)
{
	char **str = NULL;
	char *buffer;
	int i = 1;

	buffer = get_next_line(fd);
	while (buffer != NULL) {
		str = rea_and_add(str, buffer, i);
		if (!str)
			return (NULL);
		buffer = get_next_line(fd);
		i++;
	}
	return (str);
}
