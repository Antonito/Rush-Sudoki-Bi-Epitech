/*
** generate.c for generator in /tek1/semestre_02/sudoki-bi/bonus
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Feb 28 21:51:26 2016 Ludovic Petrenko
** Last update Sun Feb 28 23:39:40 2016 Antoine Baché
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "generator.h"

int	gen(char *grid, int nb)
{
  int	i;
  int	coord;

  i = 0;
  memset(grid, 0, 81);
  while (i < nb)
    {

      coord = rand() % 81;
      if (!grid[coord])
	{
	  grid[coord] = i % 8 + 1;
	  if (!check_error(grid, coord / 9, coord % 9))
	      i++;
	  else
	    grid[coord] = 0;
	}
    }
  return (1);
}

int	generate(int fd, int difficulty)
{
  char	grid[81];
  int	nb;

  srand(time(NULL));
  nb = 27 - 3 * difficulty + rand() % 4;
  while (gen(grid, nb) && !is_solvable(grid));
  return (showGrid(grid, fd));
}
