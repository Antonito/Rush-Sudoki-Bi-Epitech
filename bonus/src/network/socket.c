/*
** socket.c for sudoki in /home/bache_a/sudoki-bi/bonus/src/network
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 14:28:36 2016 Antoine Baché
** Last update Sat Feb 27 14:54:48 2016 Antoine Baché
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "network.h"

int	socket_r_int(int fd)
{
  int	nb;

  if (recv(fd, &nb, sizeof(int), 0) == -1)
    {
      write(2, "Error receiving data\n", 21);
      return (-1);
    }
  return (nb);
}

char	*socket_read(int fd)
{
  char	*received;
  int	nb;

  if (fd == -1)
    return (NULL);
  if ((received = malloc(BUFF_SIZE + 1)) == NULL)
    return (NULL);
  if ((nb = read(fd, received, BUFF_SIZE)) == -1)
    return (NULL);
  received[nb] = '\0';
  return (received);
}

int	socket_send(int fd, char *msg)
{
  if (write(fd, msg, strlen(msg)) == -1)
    {
      write(2, "Error sending data\n", 19);
      return (1);
    }
  return (0);
}

int	socket_send_int(int fd, int msg)
{
  if (write(fd, &msg, sizeof(int)) == -1)
    {
      write(2, "Error sending data\n", 19);
      return (1);
    }
  return (0);
}
