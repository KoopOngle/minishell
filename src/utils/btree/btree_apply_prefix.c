/*
** EPITECH PROJECT, 2017
** btree_apply_prefix
** File description:
** apply prefix
*/

#include <stdlib.h>
#include "btree.h"
#include "my_printf.h"

void btree_apply_prefix(btree_t *root)
{
	int i = 0;
	while (root->value[i] != 0)
		my_printf("%s ", root->value[i++]);
	my_printf("\n");
	if (root->left != NULL) {
		my_printf("gauche");
		btree_apply_prefix(root->left);
	}
	if (root->right != NULL) {
		my_printf("droite");
		btree_apply_prefix(root->right);
	}
}
