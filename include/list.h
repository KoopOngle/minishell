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
	struct list *next;
} list_t;

int list_size(list_t *begin);
int put_in_list(list_t **list, void *data);

#endif /* LIST_H_ */
