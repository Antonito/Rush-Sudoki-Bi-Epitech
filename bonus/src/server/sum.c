/*
** sum.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Fri Feb 26 22:26:48 2016 Ludovic Petrenko
** Last update Sun Feb 28 21:29:13 2016 Antoine Baché
*/

#include <stdarg.h>
#include <stdio.h>
#include "server.h"

void	clear_sol(char *bin, int i, int j, int k)
{
  int	t;
  int	u;
  int	v;

  t = -1;
  while (++t < 9)
    {
      bin[81 * i + 9 * j + t] = 0;
      bin[81 * i + 9 * t + k] = 0;
      bin[81 * t + 9 * j + k] = 0;
    }
  v = -1;
  while (++v < 3 && (u = -1))
    while (++u < 3)
      bin[81 * ((i / 3) * 3 + u) + 9 * ((j / 3) * 3 + v) + k] = 0;
  bin[81 * i + 9 * j + k] = 1;
}

void		add_sol(char *su, char *bin, int i, ...)
{
  int		j;
  int		k;
  va_list	ap;

  va_start(ap, i);
  j = va_arg(ap, int);
  k = va_arg(ap, int);
  va_end(ap);
  clear_sol(bin, i, j, k);
  su[9 * i + j] = k + 1;
}
