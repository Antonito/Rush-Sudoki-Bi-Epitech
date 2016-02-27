/*
** free.c for sudoki in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 22:10:20 2016 Antoine Baché
** Last update Fri Feb 26 22:13:53 2016 Antoine Baché
*/

#include <stdlib.h>

void	free_grid(int **tab)
{
  int	i;

  i = 0;
  while (i < 9)
    free(tab[i++]);
  free(tab);
}
