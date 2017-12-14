/*
** EPITECH PROJECT, 2017
** env.h
** File description:
** environement structure and prototype
*/

#ifndef ENV_H_
#define ENV_H_

typedef struct btree btree_t;
typedef struct list list_t;
typedef struct env_var env_var_t;

struct env_var
{
        char *name;
        char *value;
};

void env(list_t *l_env);
char **to_str_array(list_t *l_env);
char *get_env_value(list_t *l_env, char *name);
void set_env(list_t *l_env, char *name, char *value);
void unset_env(list_t **l_env, char *name);
char *cat_env_var(list_t *l_env, char *new_env);
void change_directory(char *str);
void my_exit();

static const char *builtins[] = {"cd", "env", "setenv", "unsetenv", "exit", NULL};
static const void (*built_func[])() = {&change_directory, &env, &set_env,
				       &unset_env, &my_exit};

#endif /* ENV_H_ */
