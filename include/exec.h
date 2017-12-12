/*
** EPITECH PROJECT, 2017
** exec.h
** File description:
** Prototypes for the execution of command
*/

#ifndef EXEC_H_
#define EXEC_H_

typedef struct btree btree_t;
typedef struct list list_t;

int write_file(char *file_name);
int append_file(char *file_name);
int read_file(char *file_name);
void read_stdin(char *word, int fd);
char *get_access(char *cmd, list_t *l_env);
void command_handler(btree_t *cmd, list_t *l_env);
void my_exec(char **argv, list_t *l_env);

int then(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout);

#endif /* EXEC_H_ */
