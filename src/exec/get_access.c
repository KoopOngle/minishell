/*
** EPITECH PROJECT, 2017
** get_access.h
** File description:
** return the path of the access if it accessible
*/

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include "my_printf.h"
#include "list.h"
#include "string.h"
#include "env.h"
#include "parser.h"
#include "error.h"

static char *handle_realpath(char *cmd)
{
	int rval;

	rval = access(cmd, F_OK);
	if (rval == -1) {
		my_print_err(cmd);
		return (NULL);
	}
	rval = access(cmd, X_OK);
	if (rval == -1) {
		my_print_err(cmd);
		return (NULL);
	}
	return(cmd);
}

static char *parse_d_name(char *d_name, char *path_dir)
{
	char *result = malloc(sizeof(char) * len(d_name) + len(path_dir) + 3);
	int i = 0;
	int j = 0;

	if (d_name && d_name[0] == '/')
		return (d_name);
	if (d_name && path_dir && result) {
		while (path_dir[i] != '\0') {
			result[i] = path_dir[i];
			i++;
		}
		result[i] = '/';
		i++;
		while (d_name[j] != '\0') {
			result[i++] = d_name[j++];
		}
		result[i] = '\0';
	}
	return (result);
}

static char *get_in_dir(char *path, char *cmd)
{
	DIR *dirpath = opendir(path);
	struct dirent *dp = NULL;                                                                                                                                                            

	if (dirpath == NULL)
		return (NULL);
	dp = readdir(dirpath);
	while (dp) {
		if (compare(dp->d_name, cmd) == 0)
			return (parse_d_name(cmd, path));
	        dp = readdir(dirpath);
	}
	return (NULL);
}

char *get_access(char *cmd, list_t *l_env)
{
	char *path = get_env_value(l_env, "PATH");
	char **word_a = env_var_to_word_array(path, ':');
	int i = 0;
	char *result;

	if (cmd && (cmd[0] == '/' || cmd[0] == '.'))
		return (handle_realpath(cmd));
	while (word_a && word_a[i] != NULL) {
		result = get_in_dir(word_a[i++], cmd);
		if (result != NULL)
			break;
	}
	if (result == NULL)
		my_dprintf(2, "%s: No such file or directory", cmd);
	return ((result != NULL) ? handle_realpath(result) : NULL);
}
