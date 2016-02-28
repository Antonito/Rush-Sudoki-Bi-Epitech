/*
** main.c for sudoki in /home/bache_a/sudoki-bi/bonus/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 15:07:08 2016 Antoine Baché
** Last update Sun Feb 28 23:38:09 2016 Antoine Baché
*/

#include <string.h>
#include "server.h"
#include "errors.h"

void	receive_map(int fd, char *grid)
{
  if (receive_grid(grid, fd, false) || solve(grid) || send_grid(grid, fd))
    return ;
}

int	server_loop(int fd, char *grid, char *tmp)
{
  free(tmp);
  if (socket_send(fd, "OK"))
    return (1);
  receive_map(fd, grid);
  usleep(15000);
  return (0);
}

int	start_serv(char *port)
{
  int	fd;
  int	serv_fd;
  char	*tmp;
  char	*grid;

  if ((fd = server(atoi(port), &serv_fd)) == -1 ||
      (grid = malloc(81)) == NULL)
    return (1);
  while (42 && (fd = accept_client(serv_fd)) >= 0)
    while (42 && (tmp = socket_read(fd)))
      {
	if (strncmp(tmp, "Hello", 5) != 0 &&
	    write(2, "[INFOS] Client disconnected\n", 28) > -2)
	  {
	    if (socket_send(fd, "OK") || close(fd) < 0)
	      return (1);
	    else if (!free_tmp(tmp))
	      break;
	  }
	if (server_loop(fd, grid, tmp))
	  return (1);
      }
  return (0);
}

int	main(int ac, char **av, char **env)
{
  if (!*env)
    return (1);
  if (ac != 2)
    {
      write(2, "Usage: ./server port\n", 21);
      return (1);
    }
  if (start_serv(av[1]))
    return (1);
  return (0);
}
