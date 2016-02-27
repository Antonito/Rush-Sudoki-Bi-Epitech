/*
** parse.c for sudoki in /home/bache_a/sudoki-bi/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 23:07:33 2016 Antoine Baché
** Last update Sat Feb 27 20:05:55 2016 Antoine Baché
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "errors.h"
#include "client.h"
#include "network.h"

int	fillGrid(char buff[], int *grid)
{
  int	i;
  int	j;

  memset(grid, 0, sizeof(int) * 9);
  i = 0;
  j = -1;
  while (i < 20)
    {
      if (j < 9 && !(i & 1))
	{
	  if (buff[i] > '0' && buff[i] <= '9')
	    grid[j] = atoi(&buff[i]);
	  ++j;
	}
      ++i;
    }
  return (0);
}

int	checkGrid(char buff[], int i, int loop)
{
  int	j;

  if ((loop == 0 || loop == 10) &&
      strcmp(buff, "|------------------|\n"))
    return (errorMapError());
  if (i > 0 && i < 10 && (buff[0] != '|' || buff[19] != '|'))
    return (errorMapError());
  j = 0;
  while (loop != 0 && loop != 10 && ++j < 19)
    if (buff[j] != ' ' && (buff[j] < '1' || buff[j] > '9'))
      return (errorMapError());
  return (0);
}

int	readOneGrid(int **grid, int *check, bool start)
{
  char	buff[22];
  int	loop;
  int	i;

  memset(buff, 0, 22);
  i = 0;
  loop = 0;
  while (loop < 11 && (*check = read(0, buff, 21)) > 0)
    {
      if (checkGrid(buff, i, loop))
	return (1);
      if (i < 9 && fillGrid(buff, grid[i]))
	return (1);
      if (loop++ > 0)
	++i;
    }
  if (loop == 11)
    {
      if (!start && printf("####################\n") < 0)
	return (1);
      return (2);
    }
  return (0);
}

int	readGrid(int **grid, int fd)
{
  int	check;
  bool	start;
  int	check_read;
  char	*tmp;

  check = -1;
  start = true;
  while (check)
    {
      if (socket_send(fd, "Hello") || !(tmp = socket_read(fd)) ||
	  strncmp(tmp, "OK", 2) != 0 ||
	  (check_read = readOneGrid(grid, &check, start)) == 1)
	return (1);
      free(tmp);
      if (check_read == 2 && send_server(grid, fd))
	return (1);
      if (start)
	start = false;
    }
  if (socket_send(fd, "ByeBye") ||
      !(tmp = socket_read(fd)) || close(fd) < 0)
    return (1);
  free(tmp);
  return (0);
}
