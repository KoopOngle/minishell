/*
** EPITECH PROJECT, 2017
** env_var_to_word_array.c
** File description:
** cut the env_var to word array
*/

#include <stdlib.h>
#include <unistd.h>
#include "string.h"
#include "memory.h"
#include "my_printf.h"

static int get_number_of_sep(char *str, char separator)
{
	int i = 0;
	int nb = 0;

	while (str && str[i] != '\0')
		if (str[i++] == separator)
			nb++;
	return (nb);
}

char **env_var_to_word_array(char *env_var, char separator)
{
	int i = (env_var && env_var[0] == separator) ? 1 : 0;
	int y = 0;
	int nb = get_number_of_sep(env_var, separator);
	char **word_a = malloc(sizeof(char *) * (nb + 4));

	word_a[nb] = NULL;
	while (y < (nb + 1)) {
		word_a[y++] = my_dup("");
	}
	y = 0;
	while (env_var && env_var[i] != '\0') {
		if (env_var[i] == separator) {
			y++;
		} else {
			my_sprintf(&(word_a[y]),"%c", env_var[i]);
		}
		i++;
	}
	word_a[y + 1] = NULL;
	return (word_a);
}
