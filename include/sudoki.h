/*
** sudoki.h for Corewar in /home/bache_a/sudoki-bi/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Feb 26 20:33:02 2016 Antoine Baché
** Last update Sun Feb 28 21:22:37 2016 Antoine Baché
*/

#ifndef	SUDOKI_H_
# define SUDOKI_H_

# define	SUDOKU_LINE	9

# include	<stdbool.h>

int		showGridError(void);
int		showGrid(char *);
int		is_solved(char *);
void		*my_malloc(int);

/*
** backtrack.c
*/
char		*backtrack(char *, int);

/*
** parse.c
*/
int		fillGrid(char [], char *);
int		checkGrid(char [], int, int);
int		readOneGrid(char *, int *, bool);
int		readGrid(char *);

/*
** pass.c
*/
int		pass(char *, char *);

/*
** solve.c
*/
void		prepare_tab(char *, char *);
char		*set_tab(int);
int		solve(char*);

/*
** sum.c
*/
void		add_sol(char *, char *, int, ...);

#endif /* !SUDOKI_H_ */
