/*
** EPITECH PROJECT, 2017
** get_n_next_line.c
** File description:
** Return the n next lines.
*/

#include <stdlib.h>
#include "get_next_line.h"

char **get_n_next_line(int fd, int n)
{
	char **to_return = malloc(sizeof(char *) * n);

	if (to_return == NULL)
		return (NULL);
	for (int i = 0; i < n; i++) {
		to_return[i] = get_next_line(fd);
		if (to_return[i] == NULL)
			return (NULL);
	}
	return (to_return);
}
