/*
** EPITECH PROJECT, 2017
** get_next_line.h
** File description:
** Header file for the get_next_line project
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#ifndef READ_SIZE
	#define READ_SIZE 32000
#endif /* !READ_SIZE */

char *get_next_line(int fd, char separator);
char **get_file_in_line(int fd, char separator);
char **get_n_next_line(int fd, char separator, int n);

#endif /* GET_NEXT_LINE_H_ */
