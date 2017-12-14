/*
** EPITECH PROJECT, 2017
** btree_insert_data.c
** File description:
** insert data in btree
*/

#include <stdlib.h>
#include "btree.h"
#include "string.h"
#include "my_printf.h"

static int get_prio(char *str)
{
	if (compare(str, ";") == 0)
		return (2);
	else if (compare(str, "|") == 0 || compare(str, "<<") == 0 ||
		 compare(str, ">") == 0 || compare(str, "<") == 0 ||
		 compare(str, ">>") == 0)
		return (1);
	else
		return (0);
}

static void insert_data_nosep(btree_t **root, char **value, int is_first_op)
{
	if ((*root)->left == NULL)
		btree_insert_data(&(*root)->left, value, is_first_op);
	else
		btree_insert_data(&(*root)->right, value, is_first_op);
}

static void insert_data_sep(btree_t **root, char **value, int is_first_op)
{
	btree_t *new_node;
		
	if (get_prio((*root)->right->value[0]) == 1)
		btree_insert_data(&(*root)->right, value, is_first_op);
	else {
		new_node = btree_create_node(value);
		new_node->left = (*root)->right;
		(*root)->right = new_node;
	}
}

void btree_insert_data(btree_t **root, char **value, int is_first_op)
{
	int comp;
	btree_t *new_node;

	if (root != NULL && *root != NULL) {
		comp = get_prio(value[0]);
		if (comp == 0)
			insert_data_nosep(root, value, is_first_op);
	        else if (comp == 2 || is_first_op == 1) {
			new_node = btree_create_node(value);
			new_node->left = *root;
			*root = new_node;
		} else
			insert_data_sep(root, value, is_first_op);
	} else if (root != NULL && *root == NULL)
		*root = btree_create_node(value);
}
