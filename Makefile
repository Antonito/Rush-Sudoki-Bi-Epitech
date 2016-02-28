##
## Makefile for sudoki-bi in /home/bache_a/sudoki-bi
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Last update Sun Feb 28 01:36:23 2016 Antoine Baché
##

DEBUG=			no

SRC_PREFIX=		src/

SRC_FILES=		backtrack.c	\
			errors.c	\
			free.c		\
			is_solved.c	\
			main.c		\
			parse.c		\
			pass.c		\
			show.c		\
			solve.c		\
			sum.c

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

NAME=			bin/sudoki-bi

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -ansi -pedantic -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror -ansi -pedantic
endif

CC=			gcc

RM=			rm -f

OBJ=			$(SRC:.c=.o)

$(NAME):	$(OBJ)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled sudoki"
	@$(CC) $(OBJ) -o $(NAME)

%.o:%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME) $(NAME_SERVER)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting" $(NAME) "..."
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
