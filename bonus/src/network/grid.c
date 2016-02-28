/*
** grid.c for sudoki in /home/bache_a/sudoki-bi/bonus/src/network
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 15:28:13 2016 Antoine Baché
** Last update Sun Feb 28 21:22:01 2016 Antoine Baché
*/

#include <stdlib.h>
#include "network.h"

int	send_grid(char *grid, int fd)
{
  int	i;
  char	*tmp;

  i = 0;
  while (i < 81)
    {
      if (socket_send(fd, &grid[i]) || (tmp = socket_read(fd)) == NULL)
	return (1);
      free(tmp);
      ++i;
    }
  return (0);
}

int	receive_grid(char *grid, int fd, bool solved)
{
  int	i;
  char	*tmp;
  bool	check;

  i = 0;
  check = false;
  while (i < 81)
    {
      if ((tmp = socket_read(fd)) == NULL ||
	  !(grid[i] = *tmp) ||
	  grid[i] > 9 ||
	  socket_send(fd, "OK"))
	{
	  return (1);
	}
      free(tmp);
      if (solved == true && check == false && grid[i] == 0)
	check = true;
      ++i;
    }
  if (check)
    return (2);
  return (0);
}
