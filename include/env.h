/*
** EPITECH PROJECT, 2017
** env.h
** File description:
** environement structure and prototype
*/

#ifndef ENV_H_
#define ENV_H_

typedef struct env_var env_var_t;

struct env_var
{
        char *name;
        char *value;
};

char **get_env();
char **to_str_array(list_t *l_env);
char *get_env_value(list_t *l_env, char *name);

#endif /* ENV_H_ */
