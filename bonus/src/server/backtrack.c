/*
** backtrack.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Feb 27 06:47:24 2016 Ludovic Petrenko
** Last update Sun Feb 28 19:24:45 2016 Ludovic Petrenko
*/

#include <stdlib.h>
#include "server.h"

int	check_error(int **grid, int i, int j)
{
  int	t;
  int	x;
  int	y;

  t = -1;
  while (++t < 9 && grid[i][j])
    {
      x = i / 3 * 3 + t / 3;
      y = j / 3 * 3 + t % 3;
      if ((grid[i][j] == grid[i][t] && t != j) ||
	  (grid[i][j] == grid[t][j] && t != i) ||
	  (grid[i][j] == grid[x][y] && !(x == i && y == j)))
	return (1);
    }
  return (0);
}

int	**cp_grid(int **grid)
{
  int	i;
  int	j;
  int	**res;

  if ((res = malloc(9 * sizeof(int *))) == NULL)
    return (NULL);
  i = 0;
  while (i < 9)
    {
      if ((res[i] = malloc(9 * sizeof(int))) == NULL)
	return (NULL);
      j = 0;
      while (j < 9)
	{
	  res[i][j] = grid[i][j];
	  j++;
	}
      i++;
    }
  return (res);
}

int	**backtrack(int **s, int i)
{
  int	**res;
  int	**su;
  int	t;

  if ((su = cp_grid(s)) == NULL)
    return (NULL);
  if (i == 81)
    return (su);
  if (s[i / 9][i % 9])
    return (free_grid(su), backtrack(s, i + 1));
  t = -1;
  while (++t < 9)
    {
      su[i / 9][i % 9] = t + 1;
      if (!check_error(su, i / 9, i % 9) &&
	  (res = backtrack(su, i + 1)) != NULL)
	return (free_grid(su), res);
    }
  return (NULL);
}
