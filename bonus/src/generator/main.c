/*
** main.c for Generator in /home/bache_a/sudoki-bi/bonus/src/generator
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 02:04:37 2016 Antoine Baché
** Last update Sun Feb 28 19:23:36 2016 Ludovic Petrenko
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
      difficulty = my_getnbr(av[1]);
      if (ac == 3 && (fd = creat(av[2], 0655)) == -1 && (fd = 1))
	dprintf(2, "Failed to create the file \"%s\"\n", av[2]);
    }
  else if (ac > 1)
    dprintf(2, "Usage: ./generator [difficulty] [output file]\n\
difficulty: 0 = easy 4 = hard (0 by default)\n\
output: by default standard output\n");
  if (generate(fd, difficulty))
    return (1);
  if (fd > 2)
    close(fd);
  return (0);
}
