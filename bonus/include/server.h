/*
** server.h for Sudoki in /home/bache_a/sudoki-bi/bonus/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 15:12:50 2016 Antoine Baché
** Last update Sun Feb 28 01:09:46 2016 Antoine Baché
*/

#ifndef	SERVER_H_
# define SERVER_H_

# define _DEFAULT_SOURCE
# define _POSIX_SOURCE
# define _BSD_SOURCE

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
void		free_grid(int **);

/*
** is_solved.c
*/
int		is_solved(int **);

/*
** backtrack.c
*/
int		**backtrack(int **, int);

/*
** pass.c
*/
int		pass(int **, int ***);

/*
** solve.c
*/
void		prepare_tab(int **, int ***);
int		***set_tab(int);
int		solve(int **);

/*
** sum.c
*/
void		add_sol(int **, int ***, int, ...);

#endif /* !SERVER_H_ */
