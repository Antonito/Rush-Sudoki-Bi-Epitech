/*
** is_solved.c for sudoki in /home/petren_l/rendu/tek1/semestre_02/sudoki-bi
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Fri Feb 26 23:48:39 2016 Ludovic Petrenko
** Last update Sun Feb 28 20:05:53 2016 Ludovic Petrenko
*/

#include "sudoki.h"

int	is_solved(char *su)
{
  int	i;

  i = 0;
  while (i < 81)
    if (!su[i++])
      return (0);
  return (1);
}
