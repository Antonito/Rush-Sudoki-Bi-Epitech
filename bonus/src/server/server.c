/*
** server.c for sudoki in /home/bache_a/sudoki-bi/bonus/src/server
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Feb 27 15:11:28 2016 Antoine Baché
** Last update Sat Feb 27 20:59:14 2016 Antoine Baché
*/

#include "server.h"

int	free_tmp(char *tmp)
{
  free(tmp);
  return (0);
}

int	bind_serv(struct sockaddr_in *serv, int fd, int port)
{
  serv->sin_addr.s_addr = INADDR_ANY;
  serv->sin_family = AF_INET;
  serv->sin_port = htons(port);
  if (bind(fd, (struct sockaddr *)serv, sizeof(*serv)) == -1)
    {
      write(2, "[ERROR] Cannot start server\n", 28);
      return (1);
    }
  return (0);
}

int			accept_client(int fd)
{
  int			final;
  int			socket_size;
  struct sockaddr_in	client;

  socket_size = sizeof(struct sockaddr_in);
  if ((final = accept(fd, (struct sockaddr *)&client,
		      (socklen_t *)&socket_size)) < 0)
    {
      write(2, "[ERROR] Cannot accept client\n", 29);
      return (-1);
    }
  write(1, "[INFOS] New client connected\n", 29);
  return (final);
}

int			server(int port, int *fd)
{
  struct sockaddr_in	serv;

  if ((*fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      write(2, "[ERROR] Cannot create socket\n", 29);
      return (-1);
    }
  if (bind_serv(&serv, *fd, port) == 1)
    return (-1);
  listen(*fd, 1);
  return (0);
}
