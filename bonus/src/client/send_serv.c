/*
** send_serv.c for sudoki in /home/bache_a/sudoki-bi/bonus/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 14:15:51 2016 Antoine Baché
** Last update Sun Feb 28 21:16:37 2016 Antoine Baché
*/

#include <unistd.h>
#include <stdlib.h>
#include "client.h"
#include "network.h"

int			start_connect(char *ip, char *port)
{
  int			fd;
  int			port_nb;
  struct sockaddr_in	serv;

  port_nb = atoi(port);
  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      write(2, "Cannot create socket\n", 21);
      return (-1);
    }
  serv.sin_addr.s_addr = inet_addr(ip);
  serv.sin_family = AF_INET;
  serv.sin_port = htons(port_nb);
  if (connect(fd, (struct sockaddr *)&serv, sizeof(serv)) == -1)
    {
      write(2, "Cannot establish connection\n", 28);
      return (-1);
    }
  return (fd);
}

int	send_server(char *grid, int fd)
{
  int	check;

  if (send_grid(grid, fd) || (check = receive_grid(grid, fd, true)) == 1)
    {
      free(grid);
      return (1);
    }
  if (!check && showGrid(grid))
    {
      free(grid);
      return (1);
    }
  if (check == 2 && showGridError())
    {
      free(grid);
      return (1);
    }
  return (0);
}
