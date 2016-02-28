/*
** errors.c for sudoki in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 21:09:57 2016 Antoine Baché
** Last update Sun Feb 28 21:28:44 2016 Antoine Baché
*/

#include <stdlib.h>
#include "server.h"

int	errorMapError(void)
{
  write(1, "MAP ERROR\n", 10);
  return (1);
}

void	*my_malloc(int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    write(2, "[Error] Cannot malloc\n", 22);
  return (ptr);
}
