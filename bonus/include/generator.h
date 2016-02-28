/*
** generator.h for generator in /tek1/semestre_02/sudoki-bi/bonus
** 
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
** 
** Started on  Sun Feb 28 22:19:09 2016 Ludovic Petrenko
** Last update Sun Feb 28 23:30:57 2016 Ludovic Petrenko
*/

#ifndef GENERATOR_H_
# define GENERATOR_H_

# define MIN(A, B) ((A) <= (B) ? (A) : (B))

void		add_sol(char *, char *n, int, ...);
int		check_args(int, char **);
int		check_error(char *, int, int);
void		clear_sol(char *, int, int, int);
int		gen(char *, int);
int		generate(int, int);
int		is_numeric(char *);
int		is_solvable(char *);
int		is_solved(char *);
void		*my_malloc(int);
int		pass(char *, char *);
void		prepare_tab(char *, char *);
char		*set_tab(int);
int		showGrid(char *, int);
int		sum_column(char *, int, int);
int		sum_line(char *, int, int);
int		sum_square(char *, int, int, int);
int		sum_untitled(char *, int, int);

#endif /* !GENERATOR_H_ */
