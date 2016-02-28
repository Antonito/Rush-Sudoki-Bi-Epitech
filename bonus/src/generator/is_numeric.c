/*
** is_numeric.c for generator in /tek1/semestre_02/sudoki-bi/bonus
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Sun Feb 28 19:32:04 2016 Ludovic Petrenko
** Last update Sun Feb 28 19:32:59 2016 Ludovic Petrenko
*/

#include "generator.h"

int	is_numeric(char *s)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] < 48 || s[i] > 58)
	return (0);
      i++;
    }
  return (1);
}
