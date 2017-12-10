/*
** EPITECH PROJECT, 2017
** string.h
** File description:
** string.h
*/

#ifndef STRING_H_
#define STRING_H_

int len(char *str);
int cat(char **dest, char *src);
int ncat(char **dest, char *src, int length);
int cat_char(char **str, char c);
int contain(char *str, char c);
int is_digit(char c);
int compare(char *str1, char *str2);
int my_atoi(char const *str);
char *my_dup(char *str);

#endif /* STRING_H_ */
