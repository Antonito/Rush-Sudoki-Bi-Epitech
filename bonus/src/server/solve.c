/*
** solve.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Fri Feb 26 21:06:30 2016 Ludovic Petrenko
** Last update Sun Feb 28 21:36:13 2016 Antoine Baché
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "server.h"
#include "errors.h"

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

int	solve(char *su)
{
  char	*bin;
  char	*res;

  if ((bin = set_tab(1)) == NULL)
    return (1);
  prepare_tab(su, bin);
  while (!is_solved(su))
    {
      if (!pass(su, bin) && !is_solved(su))
  	{
	  if ((res = backtrack(su, 0)) == NULL)
	    {
	      free(bin);
	      return (0);
	    }
	  free(bin);
	  free(res);
	  return (0);
  	}
    }
  return (0);
}
