/*
** send_serv.c for sudoki in /home/bache_a/sudoki-bi/bonus/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 14:15:51 2016 Antoine Baché
** Last update Sat Feb 27 15:01:21 2016 Antoine Baché
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

int	send_grid(int **grid, int fd)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  while (i < 9 && !(j = 0))
    {
      while (j < 9)
	{
	  if (socket_send_int(fd, grid[i][j]) || !(tmp = socket_read(fd)))
	    return (1);
	  free(tmp);
	  ++j;
	}
      ++i;
    }
  return (0);
}

int	receive_grid(int **grid, int fd)
{
  int	i;
  int	j;

  i = 0;
  while (i < 9 && !(j = 0))
    {
      while (j < 9)
	{
	  if ((grid[i][j] = socket_r_int(fd)) == -1 || grid[i][j] > 9 ||
	      socket_send(fd, "OK"))
	    return (1);
	  if (grid[i][j] == 0)
	    return (2);
	  ++j;
	}
      ++i;
    }
  return (0);
}

int	send_server(int **grid, char *ip, char *port)
{
  int	check;
  int	fd;

  if ((fd = start_connect(ip, port)) == -1)
    {
      free_grid(grid);
      return (1);
    }
  if (send_grid(grid, fd) || (check = receive_grid(grid, fd)) == 1)
    {
      free_grid(grid);
      return (1);
    }
  if (!check && showGrid(grid))
    {
      free_grid(grid);
      return (1);
    }
  if (check == 2 && showGridError())
    {
      free_grid(grid);
      return (1);
    }
  return (0);
}
