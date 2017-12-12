/*
** EPITECH PROJECT, 2017
** evalexpr.c
** File description:
** eval expr
*/

#include <stdlib.h>
#include "string.h"
#include "my_printf.h"
#include "memory.h"
#include "btree.h"

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

static int get_next_op(char **word_array, int i)
{
	if (word_array == NULL || word_array[i] == NULL)
		return (-1);
	while (word_array && word_array[i] != NULL) {
		if (get_prio(word_array[i]))
			break;
		i++;
	}
	return (i);
}

static void launch_insert_data(btree_t **node, char **word_array, int k)
{
	if (k == 1)
		btree_insert_data(node, word_array, 1);
	else
		btree_insert_data(node, word_array, 0);
}

btree_t *create_btree(char **word_array)
{
	btree_t *node = NULL;
	int i = 0;
	int y = 0;
	int k = 0;
	int nb = get_next_op(word_array, i);
	char **strd = my_calloc(sizeof(char *) * (nb + 1));

	while (i <= nb) {
		strd[y++] = my_dup(word_array[i++]);
		if (i >= nb) {
			launch_insert_data(&node, strd, k); 
			k++;
			y = 0;
			nb = get_next_op(word_array, i);
			strd = my_calloc(sizeof(char *) * (nb + 1));
		}
	}
	return (node);
}
