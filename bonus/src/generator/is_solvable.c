/*
** solve.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Fri Feb 26 21:06:30 2016 Ludovic Petrenko
** Last update Sun Feb 28 23:13:48 2016 Ludovic Petrenko
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

char	*set_tab(int value)
{
  int	i;
  char	*tab;

  i = 0;
  if ((tab = my_malloc(729)) == NULL)
    return (NULL);
  while (i < 729)
    {
      tab[i] = value;
      i++;
    }
  return (tab);
}

void	prepare_tab(char *su, char *bin)
{
  int	i;
  int	j;
  int	t;

  j = -1;
  while (++j < 9 && (i = -1))
    while (++i < 9)
      {
	t = 9 * i + j;
	if (su[t])
	  add_sol(su, bin, i, j, su[t] - 1);
      }
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

int	is_solvable(char *cp)
{
  char	*bin;
  char	*su;

  if ((su = cp_grid(cp)) == NULL || (bin = set_tab(1)) == NULL)
    return (0);
  prepare_tab(su, bin);
  while (!is_solved(su))
    if (!pass(su, bin) && !is_solved(su))
      return (free(bin), 0);
  return (free(bin), 1);
}
