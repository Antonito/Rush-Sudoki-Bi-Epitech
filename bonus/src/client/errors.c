/*
** errors.c for sudoki in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 21:09:57 2016 Antoine Baché
** Last update Sat Feb 27 00:52:32 2016 Antoine Baché
*/

#include <unistd.h>

int	errorMapError(void)
{
  write(1, "MAP ERROR\n", 10);
  return (1);
}

int	errorMalloc(void)
{
  write(2, "[Error] Cannot malloc\n", 22);
  return (1);
}
