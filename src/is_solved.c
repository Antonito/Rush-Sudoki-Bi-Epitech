/*
** is_solved.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Fri Feb 26 23:48:39 2016 Ludovic Petrenko
** Last update Fri Feb 26 23:50:55 2016 Ludovic Petrenko
*/

#include "sudoki.h"

int	is_solved(int **su)
{
  int	i;
  int	j;

  j = -1;
  while (++j < 9 && (i = -1))
    while (++i < 9)
      if (su[i][j])
	return (0);
  return (1);
}