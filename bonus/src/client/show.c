/*
** show.c for sudoki in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 22:43:29 2016 Antoine Baché
** Last update Sat Feb 27 15:37:48 2016 Antoine Baché
*/

#include <stdio.h>

int	showGridError(void)
{
  if (printf("|------------------|\n| X X X X X X X X X|\n") < 0 ||
      printf("| X X X X X X X X X|\n| X X X X X X X X X|\n") < 0 ||
      printf("| X X X X X X X X X|\n| X X X X X X X X X|\n") < 0 ||
      printf("| X X X X X X X X X|\n| X X X X X X X X X|\n") < 0 ||
      printf("| X X X X X X X X X|\n| X X X X X X X X X|\n") < 0 ||
      printf("|------------------|\n") < 0)
    return (1);
  return (0);
}

int	showGrid(int **grid)
{
  int	i;

  i = 0;
  if (printf("|------------------|\n") < 0)
    return (1);
  while (i < 9)
    {
      if (printf("| %d %d %d %d %d %d %d %d %d|\n", grid[i][0], grid[i][1],
		 grid[i][2], grid[i][3], grid[i][4], grid[i][5], grid[i][6],
		 grid[i][7], grid[i][8]) < 0)
	return (1);
      ++i;
    }
  if (printf("|------------------|\n") < 0)
    return (1);
  return (0);
}
