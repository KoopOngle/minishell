/*
** EPITECH PROJECT, 2017
** list.h
** File description:
** list struct definition and prototype
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct list
{
	void *data;
	struct linked_list *next;
} list_t;

int list_size(linked_list_t *begin);
int put_in_list(linked_list_t **list, void *data);

#endif
