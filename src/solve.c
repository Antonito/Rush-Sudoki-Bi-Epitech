/*
** solve.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Fri Feb 26 21:06:30 2016 Ludovic Petrenko
** Last update Sat Feb 27 01:11:35 2016 Ludovic Petrenko
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

int	solve(int **su)
{
  int	***bin;

  if ((bin = set_tab(1)) == NULL)
    return (1);
  showGrid(su);
  prepare_tab(su, bin);
  showGrid(su);
  while (!is_solved(su))
    {
      showGrid(su);
      if (!pass(su, bin) && !is_solved(su))
	{
	  printf("This sudoku is not solvable\n");
	  return (1);
	}
    }
  return (0);
}
