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
void command_handler(btree_t *cmd, list_t *l_env);
void my_exec(char **argv, list_t *l_env);
void then_handler(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout);
void pipe_handler(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout);
void out_handler(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout);
void append_handler(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout);
void in_handler(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout);
void stdin_handler(btree_t *btree, list_t *l_env, int my_stdin, int my_stdout);

static const char *EXEC[] = {";", "|", ">", ">>", "<", "<<", NULL};
static const void (*EXEC_FUNC[])() = {&then_handler, &pipe_handler,
				      &out_handler, &append_handler,
				      &in_handler, &stdin_handler};
#endif /* EXEC_H_ */
