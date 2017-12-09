/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** Return the next line of the file
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static int is_empty_or_strlen(char *str, int empty_or_strlen)
{
	int i = 0;
	int tmp = 1;

	if (empty_or_strlen == 0) {
		for (; i < READ_SIZE; i++)
			tmp = (str[i] == 0) ? tmp : 0;
		return (tmp);
	} else {
		if (*str == '\0')
			return (0);
		while (str[i])
			i++;
		return (i);
	}
}

static void shift_str(char *str, int offset)
{
	int i = 0;

	while (i + offset < READ_SIZE) {
		str[i] = str[i + offset];
		i++;
	}
	while (i < READ_SIZE || i < offset) {
		str[i] = 0;
		i++;
	}
}

static char *my_rea_ncat(char *dest, char *src, int n)
{
	int sizes[2];
	char *res;
	int i = -1;

	if (src == NULL)
		return (dest);
	sizes[1] = is_empty_or_strlen(src, 1);
	sizes[0] = (dest == NULL) ? 0 : is_empty_or_strlen(dest, 1);
	res = malloc(sizeof(char) * (sizes[0] + sizes[1] + 1));
	if (res == NULL)
		return (NULL);
	for (int i = 0; i < (sizes[0] + sizes[1] + 1); i++)
		res[i] = 0;
	while (++i < sizes[0] + sizes[1] && i < sizes[0] + n)
		res[i] = (i < sizes[0]) ? dest[i] : src[i - sizes[0]];
	if (dest != NULL)
		free(dest);
	shift_str(src, n + 1);
	return (res);
}

static int get_pos_return(char *str)
{
	int i = 0;
	int pos = -1;

	while (i < READ_SIZE && pos == -1) {
		if (str[i] == '\n')
			pos = i;
		i++;
	}
	return (pos);
}

char *get_next_line(int fd)
{
	static char stocked[READ_SIZE];
	char *to_return = NULL;
	int cond = 1;
	int pos;
	int bool = 1;

	while (bool) {
		if (is_empty_or_strlen(stocked, 0))
			cond = read(fd, stocked, READ_SIZE);
		if (cond <= 0 && to_return == NULL)
			return (NULL);
		pos = get_pos_return(stocked);
		bool = (pos >= 0 || cond == 0) ? 0 : bool;
		pos = (pos < 0 || cond == 0) ? READ_SIZE : pos;
		to_return = my_rea_ncat(to_return, stocked, pos);
		if (to_return == NULL)
			return (NULL);
	}
	return (to_return);
}
