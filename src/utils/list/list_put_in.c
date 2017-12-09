/*
** EPITECH PROJECT, 2017
** my_list_size
** File description:
** my list size
*/

#include <stdlib.h>
#include "list.h"

int put_in_list(list_t **list, void *data)
{
	list_t *element;

	element = malloc(sizeof(*element));
	element->data = data;
	element->next = *list;
	*list = element;
	return (0);
}
