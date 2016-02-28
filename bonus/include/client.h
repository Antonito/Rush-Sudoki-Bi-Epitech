/*
** client.h for Corewar in /home/bache_a/sudoki-bi/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 20:33:02 2016 Antoine Baché
** Last update Sun Feb 28 21:26:43 2016 Antoine Baché
*/

#ifndef	CLIENT_H_
# define CLIENT_H_

# define	SUDOKU_LINE	9

# include	<stdbool.h>

int		showGridError(void);
int		showGrid(char *);
int		is_solved(int **);

/*
** parse.c
*/
int		fillGrid(char *, char *);
int		checkGrid(char *, int, int);
int		readOneGrid(char *, int *, bool);
int		readGrid(char *, int);

/*
** send_serv.c
*/
int		start_connect(char *, char *);
int		send_server(char *, int);

#endif /* !CLIENT_H_ */
