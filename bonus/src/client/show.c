/*
** show.c for sudoki in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 22:43:29 2016 Antoine Baché
** Last update Sun Feb 28 19:57:35 2016 Ludovic Petrenko
*/

#include <stdio.h>

int	showGridError(void)
{
  if (printf("|------------------|\n| X X X X X X X X X|\n") < 0 ||
      printf("| X X X X X X X X X|\n| X X X X X X X X X|\n") < 0 ||
      printf("| X X X X X X X X X|\n| X X X X X X X X X|\n") < 0 ||
      printf("| X X X X X X X X X|\n| X X X X X X X X X|\n") < 0 ||
      printf("| X X X X X X X X X|\n| X X X X X X X X X|\n") < 0 ||
      printf("|------------------|\n") < 0)
    return (1);
  return (0);
}

int	showGrid(char *grid)
{
  int	i;
  int	j;

  i = 0;
  if (printf("|------------------|\n") < 0)
    return (1);
  while (i < 9)
    {
      j = -1;
      if (printf("|") < 0)
	return (1);
      while (++j < 9)
	if (printf((grid[9 * i + j]) ? " %d" : "  ", grid[9 * i + j]) < 0)
	  return (1);
      if (printf("|\n") < 0)
	return (1);
      ++i;
    }
  if (printf("|------------------|\n") < 0)
    return (1);
  return (0);
}
