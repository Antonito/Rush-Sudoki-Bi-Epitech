/*
** main.c for sudoki-bi in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 20:32:13 2016 Antoine Baché
** Last update Sat Feb 27 16:14:59 2016 Antoine Baché
*/

#include <stdlib.h>
#include <unistd.h>
#include "client.h"
#include "errors.h"

int	sudoki(char *ip, char *port)
{
  int	**grid;
  int	i;
  int	fd;

  if (!(grid = malloc(sizeof(int *) * 9)))
    return (errorMalloc());
  i = -1;
  while (++i < 9)
    if (!(grid[i] = malloc(sizeof(int) * 9)))
      return (errorMalloc());
  if ((fd = start_connect(ip, port)) == -1)
    {
      free_grid(grid);
      return (1);
    }
  if (readGrid(grid, fd))
    return (1);
  free_grid(grid);
  return (0);
}

int	main(int ac, char **av, char **env)
{
  (void)av;
  if (!*env)
    return (1);
  if (ac != 3)
    {
      write(2, "Usage: ./client ip port < file\n", 31);
      return (1);
    }
  if (sudoki(av[1], av[2]))
    return (1);
  return (0);
}
