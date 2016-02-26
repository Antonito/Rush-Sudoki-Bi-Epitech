/*
** errors.c for sudoki in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 21:09:57 2016 Antoine Baché
** Last update Fri Feb 26 21:10:57 2016 Antoine Baché
*/

#include <unistd.h>

int	errorMalloc(void)
{
  write(2, "[Error] Cannot malloc\n", 22);
  return (1);
}
