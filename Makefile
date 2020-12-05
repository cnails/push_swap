# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnails <cnails@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/13 11:41:07 by cnails            #+#    #+#              #
#    Updated: 2020/11/13 11:57:44 by cnails           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

LIB = libft/libft.a
HEADER_NAME = push_swap.h

INCLUDES = ./includes/
INCLUDES_LIB = ./libft/includes/
SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRCS = main.c sort_utils.c

SRCS_CHECKER = checker.c sort_utils.c

HEADER = $(addprefix $(INCLUDES), $(HEADER_NAME))

SRC = $(addprefix $(SRC_DIR), $(SRCS))
SRC_CHECKER = $(addprefix $(SRC_DIR), $(SRCS_CHECKER))
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_CHECKER = $(addprefix $(OBJ_DIR), $(SRCS_CHECKER:.c=.o))

CC = gcc
FLAGS = -Wall -Werror -Wextra
C_LIB = -L ./libft -lft

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(LIB) $(HEADER)
	$(CC) $(C_LIB) $(addprefix -I, $(INCLUDES)) $(OBJ) $(FLAGS) -o $(NAME)

$(CHECKER): $(OBJ_DIR) $(OBJ_CHECKER) $(LIB) $(HEADER)
	$(CC) $(C_LIB) $(addprefix -I, $(INCLUDES)) $(OBJ_CHECK) $(FLAGS) -o $(CHECKER)

$(OBJ_DIR):
	mkdir -p obj

$(NAME_LIB):
	make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -I $(INCLUDES) -I $(INCLUDES_LIB) $(FLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft/

fclean: clean
	rm -f $(NAME) $(CHECKER)
	make fclean -C libft/

re: fclean all
