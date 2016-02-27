/*
** grid.c for sudoki in /home/bache_a/sudoki-bi/bonus/src/network
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 15:28:13 2016 Antoine Baché
** Last update Sat Feb 27 21:14:25 2016 Antoine Baché
*/

#include <stdlib.h>
#include "network.h"

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

int	receive_grid(int **grid, int fd, bool solved)
{
  int	i;
  int	j;
  bool	check;

  i = 0;
  check = false;
  while (i < 9 && !(j = 0))
    {
      while (j < 9)
	{
	  if ((grid[i][j] = socket_r_int(fd)) == -1 || grid[i][j] > 9 ||
	      socket_send(fd, "OK"))
	    {
	      return (1);
	    }
	  if (solved == true && check == false && grid[i][j] == 0)
	    check = true;
	  ++j;
	}
      ++i;
    }
  if (check)
    return (2);
  return (0);
}
