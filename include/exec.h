/*
** EPITECH PROJECT, 2017
** exec.h
** File description:
** Prototypes for the execution of command
*/

#ifndef EXEC_H_
#define EXEC_H_

int write_file(char *file_name);
int append_file(char *file_name);
int read_file(char *file_name);
void read_stdin(char *word, int fd);
char *get_access(char *cmd, list_t *l_env);

#endif /* EXEC_H_ */
