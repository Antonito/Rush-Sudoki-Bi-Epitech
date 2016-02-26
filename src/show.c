/*
** show.c for sudoki in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 22:43:29 2016 Antoine Baché
** Last update Fri Feb 26 22:47:53 2016 Antoine Baché
*/

#include <stdio.h>

void	showGrid(int **grid)
{
  int	i;

  i = 0;
  printf("|------------------|\n");
  while (i < 9)
    {
      printf("| %d %d %d %d %d %d %d %d %d|\n", grid[i][0], grid[i][1],
	     grid[i][2], grid[i][3], grid[i][4], grid[i][5], grid[i][6],
	     grid[i][7], grid[i][8]);
      ++i;
    }
  printf("|------------------|\n");
}
