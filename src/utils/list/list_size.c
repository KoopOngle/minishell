/*
** EPITECH PROJECT, 2017
** list_size.c
** File description:
** list_size
*/

#include "mylist.h"
#include <stdlib.h>

int my_list_size(linked_list_t *begin)
{
	linked_list_t *tmp = begin;
	int i = 0;

	while (tmp != NULL) {
		i++;
		tmp = tmp->next;
	}
	return (i);
}
