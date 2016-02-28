/*
** grid.c for sudoki in /home/bache_a/sudoki-bi/bonus/src/network
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 15:28:13 2016 Antoine Baché
** Last update Sun Feb 28 22:26:28 2016 Antoine Baché
*/

#include <stdlib.h>
#include <unistd.h>
#include "network.h"

int	send_grid(char *grid, int fd)
{
  char	*tmp;

  if (write(fd, grid, 81) < 0 || (tmp = socket_read(fd)) == NULL)
    return (1);
  free(tmp);
  return (0);
}

int	receive_grid(char *grid, int fd, bool solved)
{
  int	i;
  char	*tmp;
  bool	check;

  check = false;
  if ((tmp = socket_read(fd)) == NULL ||
      socket_send(fd, "OK"))
    return (1);
  i = -1;
  while (++i < 81 && (grid[i] = tmp[i]) < 127)
    if (grid[i] > 9)
      return (1);
    else if (solved == true && check == false && grid[i] == 0)
      check = true;
  i = -1;
  while (++i < 81)
    if (solved == true && check == false && grid[i] == 0)
      check = true;
  free(tmp);
  if (check)
    return (2);
  return (0);
}
