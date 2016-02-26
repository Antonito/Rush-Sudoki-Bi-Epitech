##
## Makefile for sudoki-bi in /home/bache_a/sudoki-bi
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Feb 26 20:26:29 2016 Antoine Baché
## Last update Fri Feb 26 22:44:03 2016 Antoine Baché
##

DEBUG=			yes

SRC_PREFIX=		src/

SRC_FILES=		main.c		\
			solve.c		\
			free.c		\
			parse.c		\
			show.c		\
			errors.c

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
	@echo "Compiled client"
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
