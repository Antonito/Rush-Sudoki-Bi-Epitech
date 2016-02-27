/*
** solve.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Fri Feb 26 21:06:30 2016 Ludovic Petrenko
** Last update Sun Feb 28 00:46:38 2016 Ludovic Petrenko
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "sudoki.h"

int	***set_tab(int value)
{
  int	i;
  int	j;
  int	k;
  int	***tab;

  k = -1;
  if ((tab = malloc(9 * sizeof(int**))) == NULL)
    return (NULL);
  while (++k < 9 && (j = -1))
    {
      if ((tab[k] = malloc(9 * sizeof(int*))) == NULL)
	return (NULL);
      while (++j < 9 && (i = -1))
	{
	  if ((tab[k][j] = malloc(9 * sizeof(int))) == NULL)
	    return (NULL);
	  while (++i < 9)
	    tab[k][j][i] = value;
	}
    }
  return (tab);
}

void	prepare_tab(int **su, int ***bin)
{
  int	i;
  int	j;

  j = -1;
  while (++j < 9 && (i = -1))
    while (++i < 9)
      if (su[i][j])
	add_sol(su, bin, i, j, su[i][j] - 1);
}

void	free_tab(int ***tab)
{
  int	i;

  i = 0;
  while (i < 9)
    free_grid(tab[i++]);
  free(tab);
}

int	solve(int **su)
{
  int	***bin;
  int	**res;

  if ((bin = set_tab(1)) == NULL)
    return (1);
  prepare_tab(su, bin);
  while (!is_solved(su))
    {
      if (!pass(su, bin) && !is_solved(su))
  	{
	  if ((res = backtrack(su, 0)) == NULL)
	    {
	      if (showGridError())
		return (1);
	      return (free_tab(bin), 0);
	    }
	  else if (showGrid(res))
	    return (1);
	  return (free_tab(bin), free_grid(res), 0);
  	}
    }
  return (showGrid(su));
}
