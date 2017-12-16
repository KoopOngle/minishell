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

typedef struct cmd
{
        char **value;
        int is_separator;
} cmd_t;

cmd_t *create_cmd(char **word_array);
list_t *create_cmd_list(char **word_array);
int write_file(char *file_name);
int append_file(char *file_name);
int read_file(char *file_name);
void read_stdin(char *word, int fd);
char *get_access(char *cmd, list_t *l_env);
void command_handler(list_t *cmd, list_t **l_env, int my_stdin, int my_stdout);
void my_exec(char **argv, list_t *l_env);
void then_handler(list_t *list, list_t **l_env, int my_stdin, int my_stdout);
void pipe_handler(list_t *list, list_t **l_env, int my_stdin, int my_stdout);
void out_handler(list_t *list, list_t *l_env, int *my_stdin, int *my_stdout);
void append_handler(list_t *list, list_t *l_env, int *my_stdin, int *my_stdout);
void in_handler(list_t *list, list_t *l_env, int *my_stdin, int *my_stdout);
void stdin_handler(list_t *list, list_t *l_env, int *my_stdin, int *my_stdout);
void redirect_handler(list_t *list, list_t **l_env, int my_stdin,
		      int my_stdout);
int builtins_handler(cmd_t *cmd, list_t **l_env, int my_stdin, int my_stdout);

static const char *EXEC[] = {";", "|", ">", ">>", "<", "<<", NULL};
static const void (*EXEC_FUNC[])() = {&then_handler, &pipe_handler,
				      &redirect_handler, &redirect_handler,
				      &redirect_handler, &redirect_handler};
static const char *REDIRECT[] = {">", ">>", "<", "<<", NULL};
static const void (*REDIRECT_FUNC[])() = {&out_handler, &append_handler,
					  &in_handler, &stdin_handler};
#endif /* EXEC_H_ */
