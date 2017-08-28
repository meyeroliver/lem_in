# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omeyer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/02 14:51:42 by omeyer            #+#    #+#              #
#    Updated: 2017/08/28 07:50:59 by omeyer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = file_handeling.c error_handling.c room_list.c creator.c display.c

OBJ = file_handeling.o error_handlling.o room_list.o creator.o display.o

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
