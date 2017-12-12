/*
** EPITECH PROJECT, 2017
** list.h
** File description:
** list struct definition and prototype
*/

#ifndef LIST_H_
#define LIST_H_

typedef struct list list_t;

struct list
{
	void *data;
	struct list *next;
};

int delete_node(list_t **begin, list_t *node);
list_t *get_node_by_name(list_t **begin, char *name);
int list_size(list_t *begin);
int put_in_list(list_t **list, void *data);
int delete_node_by_name(list_t **begin, char *name);
#endif /* LIST_H_ */
