/*
** server.h for Sudoki in /home/bache_a/sudoki-bi/bonus/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 15:12:50 2016 Antoine Baché
** Last update Sun Feb 28 23:36:08 2016 Ludovic Petrenko
*/

#ifndef	SERVER_H_
# define SERVER_H_

# include <unistd.h>
# include <stdlib.h>
# include "network.h"

int		bind_serv(struct sockaddr_in *, int, int);
int		accept_client(int);
int		server(int, int *);

/*
** free
*/
int		free_tmp(char *);

/*
** is_solved.c
*/
int		is_solved(char *);

/*
** backtrack.c
*/
char		*backtrack(char *, int);

/*
** pass.c
*/
int		pass(char *, char *);

/*
** solve.c
*/
void		prepare_tab(char *, char *);
char		*set_tab(int);
int		solve(char *);

/*
** sum.c
*/
void		add_sol(char *, char *, int, ...);

#endif /* !SERVER_H_ */
