/*
** sum.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Fri Feb 26 22:26:48 2016 Ludovic Petrenko
** Last update Sun Feb 28 00:05:05 2016 Ludovic Petrenko
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "sudoki.h"

void	clear_sol(int ***bin, int i, int j, int k)
{
  int	t;
  int	u;
  int	v;

  t = -1;
  /* printf("(%d, %d) %d\n", i + 1, j + 1, k + 1); */
  while (++t < 9)
    {
      bin[i][j][t] = 0;
      bin[i][t][k] = 0;
      bin[t][j][k] = 0;
    }
  v = -1;
  while (++v < 3 && (u = -1))
    while (++u < 3)
      bin[(i / 3) * 3 + u][(j / 3) * 3 + v][k] = 0;
  bin[i][j][k] = 1;
}

void		add_sol(int **su, int ***bin, int i, ...)
{
  int		j;
  int		k;
  va_list	ap;

  va_start(ap, i);
  j = va_arg(ap, int);
  k = va_arg(ap, int);
  va_end(ap);
  clear_sol(bin, i, j, k);
  su[i][j] = k + 1;
}
