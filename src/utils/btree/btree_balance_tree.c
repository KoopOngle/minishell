/*
** EPITECH PROJECT, 2017
** balance_tree.c
** File description:
** balance_tree.c
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

static void balance(btree_t **root)
{
	char **valuetemp = NULL;
	int sep_temp;

	if (((*root)->left && (*root)->right) &&
	    get_prio((*root)->left->value[0]) == 1 &&
	    get_prio((*root)->right->value[0]) == 0) {
		valuetemp = (*root)->left->value;
		sep_temp = (*root)->left->is_separator;
		(*root)->left->value = (*root)->right->value;
		(*root)->left->is_separator =
			(*root)->right->is_separator;
		(*root)->right->value = valuetemp;
		(*root)->right->is_separator = sep_temp;
	}
}

void btree_balance(btree_t **root)
{
	int comp = get_prio((*root)->value[0]);

	if (comp == 1 && root)
		balance(root);
	if ((*root)->left != NULL)
		btree_balance(&((*root)->left));
	if ((*root)->right != NULL)
		btree_balance(&((*root)->right));
}
