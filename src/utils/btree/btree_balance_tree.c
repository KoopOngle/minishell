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

static btree_t *copy_btree(btree_t *tree)
{
	btree_t *duptree = btree_create_node(tree->value);

	duptree->left = tree->left;
	duptree->right = tree->right;
	return (duptree);
}

static void balance(btree_t **root)
{
	btree_t *temp_tree;

	if (((*root)->left && (*root)->right) &&
	    get_prio((*root)->left->value[0]) == 1 &&
	    get_prio((*root)->right->value[0]) == 0) {
		temp_tree = (*root)->left;
		(*root)->left = (*root)->right;
		(*root)->right = temp_tree;
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
