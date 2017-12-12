/*
** EPITECH PROJECT, 2017
** btree_create_node.c
** File description:
** btree create node
*/

#include <stdlib.h>
#include "btree.h"
#include "string.h"

static int get_prio(char *str)
{
	if (compare(str, ";") == 0)
		return (2);
	else if (compare(str, "|") == 0 || compare(str, "<<") == 0 ||
		 compare(str, ">") == 0 || compare(str, ">>") == 0 ||
		 compare(str, "<") == 0)
		return (1);
	else
		return (0);
}

btree_t *btree_create_node(char **value)
{
	btree_t *node;

	node = malloc(sizeof(btree_t));
	node->value = value;
	node->is_separator = (value && get_prio(value[0]));
	node->left = NULL;
	node->right = NULL;
	return (node);
}
