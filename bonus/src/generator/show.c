/*
** show.c for sudoki in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 22:43:29 2016 Antoine Baché
** Last update Sun Feb 28 22:17:20 2016 Ludovic Petrenko
*/

#include <stdio.h>

int	showGrid(char *grid, int fd)
{
  int	i;
  int	j;

  i = 0;
  if (dprintf(fd, "|------------------|\n") < 0)
    return (1);
  while (i < 9)
    {
      j = -1;
      if (dprintf(fd, "|") < 0)
	return (1);
      while (++j < 9)
	if (dprintf(fd, (grid[9 * i + j]) ? " %d" : "  ", grid[9 * i + j]) < 0)
	  return (1);
      if (dprintf(fd, "|\n") < 0)
	return (1);
      ++i;
    }
  if (dprintf(fd, "|------------------|\n") < 0)
    return (1);
  return (0);
}
