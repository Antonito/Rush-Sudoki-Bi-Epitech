/*
** pass.c for sudoku in /tek1/semestre_02/sudoki-bi
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Fri Feb 26 21:23:06 2016 Ludovic Petrenko
** Last update Sun Feb 28 23:37:27 2016 Antoine Baché
*/

#include "sudoki.h"

int	sum_line(char *bin, int i, int k)
{
  int	t;
  int	sum;
  int	c;

  t = 0;
  sum = 0;
  c = 81 * i + k;
  while (t < 9)
    {
      sum += bin[9 * t + c];
      ++t;
    }
  return (sum);
}

int	sum_column(char *bin, int j, int k)
{
  int	t;
  int	sum;
  int	c;

  t = 0;
  sum = 0;
  c = 9 * j + k;
  while (t < 9)
    {
      sum += bin[81 * t + c];
      ++t;
    }
  return (sum);
}

int	sum_untitled(char *bin, int i, int j)
{
  int	t;
  int	sum;
  int	c;

  t = 0;
  sum = 0;
  c = 81 * i + 9 * j;
  while (t < 9)
    {
      sum += bin[t + c];
      ++t;
    }
  return (sum);
}

int	sum_square(char *bin, int i, int j, int k)
{
  int	u;
  int	v;
  int	sum;

  u = 0;
  i = (i / 3) * 3;
  j = (j / 3) * 3;
  sum = 0;
  while (u < 3)
    {
      v = 0;
      while (v < 3)
	{
	  sum += bin[81 * (i + u) + 9 * (j + v) + k];
	  ++v;
	}
      ++u;
    }
  return (sum);
}

int	pass(char *su, char *bin)
{
  int	change;
  int	i;
  int	j;
  int	k;
  int	sum[4];

  change = 0;
  k = -1;
  while (++k < 9 && (j = -1))
    while (++j < 9 && (i = -1))
      while (++i < 9)
	if (!su[9 * i + j] && bin[81 * i + 9 * j + k])
	  {
	    sum[0] = sum_line(bin, i, k);
	    sum[1] = sum_column(bin, j, k);
	    sum[2] = sum_untitled(bin, i, j);
	    sum[3] = sum_square(bin, i, j, k);
	    if ((sum[0] == 1 || sum[1] == 1 || sum[2] == 1 || sum[3] == 1) &&
		++change)
	      add_sol(su, bin, i, j, k);
	  }
  if (change)
    return (1);
  return (0);
}
