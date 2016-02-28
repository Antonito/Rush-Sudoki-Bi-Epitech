/*
** main.c for sudoki-bi in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 20:32:13 2016 Antoine Baché
** Last update Sun Feb 28 22:12:40 2016 Antoine Baché
*/

#include <stdlib.h>
#include <unistd.h>
#include "client.h"
#include "errors.h"

int	sudoki(char *ip, char *port)
{
  char	*grid;
  int	fd;

  if ((grid = my_malloc(81)) == NULL)
    return (1);
  memset(grid, 0, 81);
  if ((fd = start_connect(ip, port)) == -1)
    {
      free(grid);
      return (1);
    }
  if (readGrid(grid, fd))
    return (1);
  free(grid);
  return (0);
}

int	main(int ac, __attribute__((unused)) char **av, char **env)
{
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
