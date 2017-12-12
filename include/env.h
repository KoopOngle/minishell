/*
** EPITECH PROJECT, 2017
** env.h
** File description:
** environement structure and prototype
*/

#ifndef ENV_H_
#define ENV_H_

typedef struct list list_t;
typedef struct env_var env_var_t;

struct env_var
{
        char *name;
        char *value;
};

int env(list_t *l_env);
char **to_str_array(list_t *l_env);
char *get_env_value(list_t *l_env, char *name);
void set_env(list_t *l_env, char *name, char *value);
char *cat_env_var(list_t *l_env, char *new_env);

int change_directory(char *str);

#endif /* ENV_H_ */
