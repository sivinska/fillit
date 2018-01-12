# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkuraite <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 15:34:31 by gkuraite          #+#    #+#              #
#    Updated: 2018/01/11 11:53:16 by sivinska         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = correct_tetrimonos.c\
	  create_empty_table.c\
	  final_table.c\
	  find_min_square.c\
	  main_table.c\
	  place_tetri_correctly.c\
	  read_the_file.c\
	  reset_table.c\
	  show_table.c\
	  verify_table_characters.c\
	  error.c\
	  fillit.c\
	  usage.c\

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a
LIBINC = -I ./libft
LIBLINK = -L ./libft -lft

SRCDIR = ./src/
INCDIR = ./includes/

all : $(NAME)

%.o:$(SRCDIR)%.c
	$(CC) $(FLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft : $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): libft $(OBJ)
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

relibft:
	rm -rf $(LIBFT)

redlibft:
	make fclean -C ./libft/

clean : redlibft
	rm -rf $(OBJ)

fclean: clean relibft
	rm -rf $(NAME)

re: fclean all
