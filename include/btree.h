/*
** EPITECH PROJECT, 2017
** btree.h
** File description:
** btree.h
*/

#ifndef BTREE_H_
#define BTREE_H_

typedef struct btree
{
	struct btree *left;
	struct btree *right;
	char **value;
	int is_separator;
} btree_t;

void btree_balance(btree_t **root);
btree_t *btree_create_node(char **value);
void btree_insert_data(btree_t **root, char **value, int is_first_op);
void btree_apply_prefix(btree_t *root);
btree_t *create_btree(char **word_array);

#endif /* BTREE_H_ */
