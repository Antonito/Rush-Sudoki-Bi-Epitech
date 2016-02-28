/*
** backtrack.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Feb 27 06:47:24 2016 Ludovic Petrenko
** Last update Sun Feb 28 21:23:32 2016 Antoine Baché
*/

#include <stdlib.h>
#include "server.h"
#include "errors.h"

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

char	*cp_grid(char *grid)
{
  int	i;
  char	*res;

  if ((res = my_malloc(81)) == NULL)
    return (NULL);
  i = 0;
  while (i < 81)
    {
      res[i] = grid[i];
      i++;
    }
  return (res);
}

char	*backtrack(char *s, int i)
{
  char	*res;
  char	*su;
  int	t;

  if ((su = cp_grid(s)) == NULL)
    return (NULL);
  if (i == 81)
    return (su);
  if (s[i])
    return (free(su), backtrack(s, i + 1));
  t = -1;
  while (++t < 9)
    {
      su[i] = t + 1;
      if (!check_error(su, i / 9, i % 9) &&
	  (res = backtrack(su, i + 1)) != NULL)
	return (free(su), res);
    }
  return (NULL);
}
