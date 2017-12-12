/*
** EPITECH PROJECT, 2017
** my_str_to_word_array
** File description:
** str to word array
*/

#include <stdlib.h>
#include "string.h"

static int get_array_len(char *str)
{
	int length = 1;
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == ' ' && str[i + 1] != ' ')
			length = length + 1;
		i = i + 1;
	}
	return (length);
}

static char *replace_wrong_char(char *str)
{
	int str_len = len(str);
	int i = 0;
	char *str_dup = my_dup(str);

	while (i < str_len) {
		if (str[i] == ' ')
			str_dup[i] = '\0';
		i = i + 1;
	}
	return (str_dup);
}

char **my_str_to_word_array(char *str)
{
	int str_len = len(str);
	char *str_dup = my_dup(str);
	char **array = malloc(sizeof(char *) * (get_array_len(str) + 1));
	int i = 0;
	int j = 0;

	array[get_array_len(str)] = 0;
	str_dup = replace_wrong_char(str);
	while (i < str_len) {
		while(str_dup[i] == '\0' && i < str_len)
			i++;
		if (str_dup[i] != '\0') {
			array[j] = my_dup(str_dup + i);
			j++;
		}
		while(str_dup[i] != '\0' && i < str_len)
			i++;
	}
	return (array);
}
