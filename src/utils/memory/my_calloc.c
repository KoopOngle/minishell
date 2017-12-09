/*
** EPITECH PROJECT, 2017
** my_calloc.c
** File description:
** calloc function
*/

#include <stdlib.h>

void *my_calloc(int size)
{
	void *res = malloc(size);

	if (res == NULL)
		my_exit("malloc error", MALLOC_ERR);
	for (int i = 0; i < size; i++)
		((char *)res)[i] = 0;
	return (res);
}
