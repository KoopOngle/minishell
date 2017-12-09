/*
** EPITECH PROJECT, 2017
** my_list_size
** File description:
** my list size
*/

#include "mylist.h"
#include <stdlib.h>

int put_in_list(linked_list_t **list, void *data)
{
	linked_list_t *element;

	element = malloc(sizeof(*element));
	element->data = data;
	element->next = *list;
	*list = element;
	return (0);
}
