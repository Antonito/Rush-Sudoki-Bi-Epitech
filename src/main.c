/*
** main.c for sudoki-bi in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 20:32:13 2016 Antoine Baché
** Last update Fri Feb 26 23:59:11 2016 Antoine Baché
*/

#include <stdlib.h>
#include <unistd.h>
#include "sudoki.h"
#include "errors.h"

int	sudoki(void)
{
  int	**grid;
  int	i;

  if (!(grid = malloc(sizeof(int *) * 9)))
    return (errorMalloc());
  i = -1;
  while (++i < 9)
    if (!(grid[i] = malloc(sizeof(int) * 9)))
      return (errorMalloc());
  if (readGrid(grid))
    return (1);
  free_grid(grid);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  (void)av;
  if (!*env)
    return (1);
  if (ac != 1)
    {
      write(2, "Usage: ./sudoki-bi < file\n", 26);
      return (1);
    }
  if (sudoki())
    return (1);
  return (0);
}
