#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasamar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 17:19:45 by akasamar          #+#    #+#              #
#    Updated: 2018/05/07 17:19:47 by akasamar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem_in
CC = gcc
LC = ar rc
FG = -Wall -Wextra -Werror

SRC = main.c \
	   valid.c \
	   structs.c \
	   links.c \
	   findandclear.c \
	   move_n_print.c \
	   sort_n_tools.c \
	   makeway_n_printf.c \
	   enter_ants.c \

HD = .
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FG) -c $(SRC) -I $(HD)
	$(LC) $(NAME) $(OBJ)
	gcc $(FG) $(SRC) libft/libft.a -o $(NAME)

clean:
		rm -Rf *.o
cleanlib:
		make clean -C ./libft/
fcleanlib:
		make fclean -C ./libft/
		rm -Rf ./libft.libft.a
fclean: clean 
		rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean