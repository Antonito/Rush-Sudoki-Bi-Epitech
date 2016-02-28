/*
** main.c for Generator in /home/bache_a/sudoki-bi/bonus/src/generator
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 02:04:37 2016 Antoine Baché
** Last update Sun Feb 28 23:31:41 2016 Ludovic Petrenko
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "generator.h"

int	check_args(int ac, char **av)
{
  if (ac == 1)
    return (0);
  return (is_numeric(av[1]));
}

int	main(int ac, char **av, char **env)
{
  int	fd;
  int	difficulty;
  
  if (!*env)
    return (1);
  fd = 1;
  difficulty = 0;
  if (check_args(ac, av))
    {
      difficulty = MIN(atoi(av[1]), 2);
      if (ac == 3 && (fd = creat(av[2], 0655)) == -1 && (fd = 1))
	dprintf(2, "Failed to create the file \"%s\"\n", av[2]);
    }
  else if (ac > 1)
    return (dprintf(2, "Usage: ./generator [difficulty] [output file]\n\
difficulty: 0 = easy - 4 = hard (0 by default)\n\
output: standard output by default\n"), 1);
  if (generate(fd, difficulty))
    return (1);
  if (fd > 2)
    close(fd);
  return (0);
}
