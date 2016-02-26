/*
** sudoki.h for Corewar in /home/bache_a/sudoki-bi/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 20:33:02 2016 Antoine Baché
** Last update Sat Feb 27 00:31:47 2016 Antoine Baché
*/

#ifndef	SUDOKI_H_
# define SUDOKI_H_

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
int		checkGrid(char [], int);
int		readOneGrid(int **, int *, bool);
int		readGrid(int **);

/*
** pass.c
*/

int		check_line(int **, int ***);
int		check_column(int **, int ***);
int		check_untitled(int **, int ***);
int		check_square(int **, int ***);
int		pass(int **, int ***);

/*
** solve.c
*/

void		prepare_tab(int **, int ***);
int		***set_tab(int);
int		solve(int **);

/*
** sum.c
*/

int		sum_square(int ***, int, int, ...);
void		add_sol(int **, int ***, int, ...);

#endif /* !SUDOKI_H_ */
