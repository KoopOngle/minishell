/*
** EPITECH PROJECT, 2017
** my_sh.h
** File description:
** header for minishell
*/

#ifndef MY_SH_H_
#define MY_SH_H_

typedef struct list list_t;

list_t *init_sh();
void core_sh(list_t *env);

#endif /* MY_SH_H_ */
