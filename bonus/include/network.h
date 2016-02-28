/*
** network.h for sudoki in /home/bache_a/sudoki-bi/bonus/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 14:27:25 2016 Antoine Baché
** Last update Sun Feb 28 21:08:13 2016 Antoine Baché
*/

#ifndef	NETWORK_H_
# define NETWORK_H_

# define	BUFF_SIZE	4096

# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <stdbool.h>

/*
** socket.c
*/
char		*socket_read(int);
int		socket_send(int, char *);

/*
** grid.c
*/
int		send_grid(char *, int);
int		receive_grid(char *, int, bool);

#endif /* !NETWORK_H_ */
