/*
** sum.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Fri Feb 26 22:26:48 2016 Ludovic Petrenko
** Last update Sat Feb 27 01:11:23 2016 Ludovic Petrenko
*/

#include <stdarg.h>
#include "sudoki.h"

int		sum_square(int ***bin, int u, int v, ...)
{
  int		i;
  int		j;
  int		k;
  int		*sol;
  int		sum;
  va_list	ap;

  va_start(ap, v);
  k = va_arg(ap, int);
  sol = va_arg(ap, int*);
  va_end(ap);
  sum = 0;
  j = -1;
  while (++j < 3 && (i = -1))
    while (++i < 3)
      {
	if ((sum += bin[i + u][j + v][k]) == 1)
	  {
	    sol[0] = i + u;
	    sol[1] = j + v;
	    sol[2] = k;
	  }
      }
  return (sum);
}

void		add_sol(int **su, int ***bin, int i, ...)
{
  int		t;
  int		j;
  int		k;
  va_list	ap;

  va_start(ap, i);
  j = va_arg(ap, int);
  k = va_arg(ap, int);
  va_end(ap);
  t = 0;
  printf("(%d, %d) %d\n", i, j, k + 1);
  while (t < 9)
    {
      bin[i][j][t] = 0;
      bin[i][t][k] = 0;
      bin[t][j][k] = 0;
      t++;
    }
  su[i][j] = k + 1;
}
