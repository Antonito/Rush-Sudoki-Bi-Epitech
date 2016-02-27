/*
** client.h for Corewar in /home/bache_a/sudoki-bi/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 20:33:02 2016 Antoine Baché
** Last update Sat Feb 27 16:18:57 2016 Antoine Baché
*/

#ifndef	CLIENT_H_
# define CLIENT_H_

# define	SUDOKU_LINE	9

# include	<stdbool.h>

int		showGridError(void);
int		showGrid(int **);
void		free_grid(int **);
int		is_solved(int **);

/*
** parse.c
*/
int		fillGrid(char [], int *);
int		checkGrid(char [], int, int);
int		readOneGrid(int **, int *, bool);
int		readGrid(int **, int);

/*
** send_serv.c
*/
int		start_connect(char *, char *);
int		send_server(int **, int);

#endif /* !CLIENT_H_ */