# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 14:51:42 by omeyer            #+#    #+#              #
#    Updated: 2018/09/14 14:47:07 by omeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = file_handeling.c room_list.c graphs.c path_finder.c path_list.c \
	  ant_list.c move_ants.c

OBJ = file_handeling.o room_list.o graphs.o path_finder.o path_list.o \
	  ant_list.o move_ants.o

FLAGS = -Wall -Wextra -Werror
FETCHLIB = -L libft/ -lft

all: $(NAME)

$(NAME):
	@$(MAKE) -C libft/ all
	@gcc -o $(NAME) $(SRC) $(FLAGS) $(FETCHLIB)

clean:
	@$(MAKE) -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -C libft/ fclean

re:	fclean all
