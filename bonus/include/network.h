/*
** network.h for sudoki in /home/bache_a/sudoki-bi/bonus/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 14:27:25 2016 Antoine Baché
** Last update Sat Feb 27 14:52:14 2016 Antoine Baché
*/

#ifndef	NETWORK_H_
# define NETWORK_H_

# define	BUFF_SIZE	4096

# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>

int		socket_r_int(int);
char		*socket_read(int);
int		socket_send(int, char *);
int		socket_send_int(int, int);

#endif /* !NETWORK_H_ */
