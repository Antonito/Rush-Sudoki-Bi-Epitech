/*
** sudoki.h for Corewar in /home/bache_a/sudoki-bi/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 20:33:02 2016 Antoine Baché
** Last update Fri Feb 26 22:44:21 2016 Antoine Baché
*/

#ifndef	SUDOKI_H_
# define SUDOKI_H_

# define	SUDOKU_LINE	9

void		showGrid(int **);
void		free_grid(int **);

/*
** parse.c
*/
int		fillGrid(char [], int *);
int		checkGrid(char [], int);
int		readOneGrid(int **, int *);
int		readGrid(int **);

#endif /* !SUDOKI_H_ */
