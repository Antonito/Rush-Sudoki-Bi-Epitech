##
## Makefile for sudoki-bi in /home/bache_a/sudoki-bi
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Feb 26 20:26:29 2016 Antoine Baché
## Last update Sun Feb 28 22:53:24 2016 Ludovic Petrenko
##

DEBUG=			yes

SRC_PREFIX=		src/generator/

SRC_FILES=		check_error.c		\
			generate.c		\
			is_numeric.c		\
			is_solvable.c		\
			is_solved.c		\
			main.c			\
			my_malloc.c		\
			pass.c			\
			show.c			\
			sum.c

SRC_CLIENT_PREFIX=	src/client/

SRC_CLIENT_FILES=	main.c			\
			errors.c		\
			free.c			\
			parse.c			\
			show.c			\
			send_serv.c

SRC_SERV_PREFIX=	src/server/

SRC_SERV_FILES=		main.c			\
			server.c		\
			backtrack.c		\
			is_solved.c		\
			pass.c			\
			solve.c			\
			free.c			\
			sum.c

NETWORK_PREFIX=		src/network/

NETWORK_FILES=		socket.c		\
			grid.c

SRC=			$(addprefix $(SRC_PREFIX),$(SRC_FILES))

SRC_CLIENT=		$(addprefix $(SRC_CLIENT_PREFIX),$(SRC_CLIENT_FILES))

SRC_SERV=		$(addprefix $(SRC_SERV_PREFIX),$(SRC_SERV_FILES))

NETWORK=		$(addprefix $(NETWORK_PREFIX),$(NETWORK_FILES))

SRC_CLIENT+=		$(NETWORK)

SRC_SERV+=		$(NETWORK)

NAME=			generator

NAME_CLIENT=		client

NAME_SERV=		server

HEAD=			-Iinclude

ifeq ($(DEBUG), yes)
	CFLAGS=		$(HEAD) -W -Wall -Wextra -g -D DEBUG
else
	CFLAGS=		$(HEAD) -W -Wall -Wextra -Werror
endif

CC=			gcc

RM=			rm -f

OBJ=			$(SRC:.c=.o)

OBJ_CLIENT=		$(SRC_CLIENT:.c=.o)

OBJ_SERV=		$(SRC_SERV:.c=.o)

$(NAME_CLIENT):	$(NAME) $(NAME_SERV) $(OBJ_CLIENT)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled client"
	@$(CC) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERV):	$(OBJ_SERV)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled server"
	@$(CC) $(OBJ_SERV) -o $(NAME_SERV)

$(NAME):	$(OBJ)
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiled generator"
	@$(CC) $(OBJ) -o $(NAME)

%.o:%.c
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Compiling" $<
	@$(CC) -o $@ -c $< $(CFLAGS)

all:	$(NAME) $(NAME_SERV) $(NAME_CLIENT)

clean:
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Removing OBJ files ..."
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_CLIENT)
	@$(RM) $(OBJ_SERV)

fclean:	clean
	@echo -n "[ "
	@echo -n "OK"
	@echo -n " ] "
	@echo "Deleting" $(NAME) "..."
	@$(RM) $(NAME)
	@$(RM) $(NAME_CLIENT)
	@$(RM) $(NAME_SERV)

re:	fclean all

.PHONY:	all clean fclean re
