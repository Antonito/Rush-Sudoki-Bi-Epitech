/*
** pass.c for sudoku in /tek1/semestre_02/sudoki-bi
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Fri Feb 26 21:23:06 2016 Ludovic Petrenko
** Last update Fri Feb 26 23:54:24 2016 Ludovic Petrenko
*/

#include "sudoki.h"

int	check_line(int **su, int ***bin)
{
  int	i;
  int	j;
  int	k;
  int	sol;
  int	sum;
  int	change;

  i = -1;
  change = 0;
  while (++i < 9 && (k = -1))
    while (++k < 9 && (j = -1) && !(sum = 0))
      {
	while (++j < 9)
	  if ((sum += bin[i][j][k]) == 1)
	    sol = j;
	if (sum == 1 && ++change)
	  add_sol(su, bin, i, sol, k);
      }
  return (change);
}

int	check_column(int **su, int ***bin)
{
  int	i;
  int	j;
  int	k;
  int	sol;
  int	sum;
  int	change;

  j = -1;
  change = 0;
  while (++j < 9 && (k = -1))
    while (++k < 9 && (i = -1) && !(sum = 0))
      {
	while (++i < 9)
	  if ((sum += bin[i][j][k]) == 1)
	    sol = i;
	if (sum == 1 && ++change)
	  add_sol(su, bin, sol, i, k);
      }
  return (change);
}

int	check_untitled(int **su, int ***bin)
{
  int	i;
  int	j;
  int	k;
  int	sol;
  int	sum;
  int	change;

  i = -1;
  change = 0;
  while (++i < 9 && (j = -1))
    while (++j < 9 && (k = -1) && !(sum = 0))
      {
	if (su[i][j] == 0)
	  while (++k < 9)
	    if ((sum += bin[i][j][k]) == 1)
	      sol = k;
	if (sum == 1 && ++change)
	  add_sol(su, bin, i, j, sol);
      }
  return (change);
}

int	check_square(int **su, int ***bin)
{
  int	k;
  int	u;
  int	v;
  int	sol[3];
  int	sum;
  int	change;

  u = -1;
  change = 0;
  while (++u < 3 && (v = -1))
    while (++v < 3 && (k = -1) && !(sum = 0))
      while (++k < 9)
	if ((sum = sum_square(bin, 3 * u, 3 * v, k, sol)) == 1 && ++change)
	  add_sol(su, bin, sol[0], sol[1], sol[2]);
  return (change);
}

int	pass(int **su, int ***bin)
{
  int	change;

  change = 0;
  change += check_line(su, bin);
  change += check_column(su, bin);
  change += check_untitled(su, bin);
  change += check_square(su, bin);
  if (change)
    return (1);
  return (0);
}
