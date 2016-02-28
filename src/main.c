/*
** main.c for sudoki-bi in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 20:32:13 2016 Antoine Baché
** Last update Sun Feb 28 21:33:29 2016 Antoine Baché
*/

#include <stdlib.h>
#include <unistd.h>
#include "sudoki.h"
#include "errors.h"

int	sudoki(void)
{
  char	*grid;

  if ((grid = my_malloc(81)) == NULL)
    return (1);
  if (readGrid(grid))
    return (1);
  free(grid);
  return (0);
}

int	main(int ac, __attribute__((unused)) char **av, char **env)
{
  if (*env == NULL)
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
