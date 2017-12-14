/*
** EPITECH PROJECT, 2017
** pos_str_in_array.c
** File description:
** Get the index of a str in an array of string
*/

#include "string.h"

int pos_str_in_array(char **array, char *str)
{
	int pos = -1;
	int i = 0;
	
	while (array[i]) {
		if (compare(array[i], str) == 0)
			pos = i;
		i++;
	}
	return (pos);
}
