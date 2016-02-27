/*
** server.h for Sudoki in /home/bache_a/sudoki-bi/bonus/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 15:12:50 2016 Antoine Baché
** Last update Sat Feb 27 21:03:28 2016 Antoine Baché
*/

#ifndef	SERVER_H_
# define SERVER_H_

# define _DEFAULT_SOURCE
# define _POSIX_SOURCE
# define _BSD_SOURCE

# include <unistd.h>
# include <stdlib.h>
# include "network.h"

int	free_tmp(char *);
int	bind_serv(struct sockaddr_in *, int, int);
int	accept_client(int);
int	server(int, int *);

#endif /* !SERVER_H_ */
