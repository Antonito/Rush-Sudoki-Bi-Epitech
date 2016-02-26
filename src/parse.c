/*
** parse.c for sudoki in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 23:07:33 2016 Antoine Baché
** Last update Fri Feb 26 23:59:57 2016 Antoine Baché
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "sudoki.h"

int	fillGrid(char buff[], int *grid)
{
  int	i;
  int	j;

  memset(grid, 0, sizeof(int) * 9);
  i = 0;
  j = 0;
  while (i < 20)
    {
      if (j < 9 && !(i & 1))
	{
	  if (buff[i] > '0' && buff[i] <= '9')
	    grid[j] = atoi(&buff[i]);
	  ++j;
	}
      ++i;
    }
  return (0);
}

int	checkGrid(char buff[], int i)
{
  if (i > 0 && i < 10 && (buff[0] != '|' || buff[19] != '|'))
    return (1);
  return (0);
}

int	readOneGrid(int **grid, int *check)
{
  char	buff[22];
  int	loop;
  int	i;

  memset(buff, 0, 22);
  i = 0;
  loop = 0;
  while (loop < 11 && (*check = read(0, buff, 21)) > 0)
    {
      if (checkGrid(buff, i % 11))
	return (1);
      if (i < 9 && fillGrid(buff, grid[i]))
	return (1);
      if (loop > 0)
	++i;
      ++loop;
    }
  if (loop == 11)
    return (2);
  return (0);
}

int	readGrid(int **grid)
{
  int	check;
  int	check_read;

  check = 1;
  while (check)
    {
      if ((check_read = readOneGrid(grid, &check)) == 1)
	return (1);
      if (check_read == 2 && solve(grid) && showGrid(grid))
	return (1);
    }
  return (0);
}
