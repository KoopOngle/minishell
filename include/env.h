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

#endif /* ENV_H_ */
