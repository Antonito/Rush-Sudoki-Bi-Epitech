/*
** backtrack.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Feb 27 06:47:24 2016 Ludovic Petrenko
** Last update Sun Feb 28 23:39:14 2016 Antoine Baché
*/

#include <stdlib.h>
#include "generator.h"

int	check_error(char *grid, int i, int j)
{
  int	t;
  int	x;
  int	y;
  int	k;

  t = -1;
  k =  i * 9 + j;
  while (++t < 9 && grid[k])
    {
      x = i / 3 * 3 + t / 3;
      y = j / 3 * 3 + t % 3;
      if ((grid[k] == grid[k - j + t] && t != j) ||
	  (grid[k] == grid[t * 9 + j] && t != i) ||
	  (grid[k] == grid[x * 9 + y] && !(x == i && y == j)))
	return (1);
    }
  return (0);
}
