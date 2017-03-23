# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrembusc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/04 18:31:39 by mrembusc          #+#    #+#              #
#    Updated: 2016/12/11 16:36:10 by mrembusc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##PROJECT
NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror

##DIRECTORIES
SRC_PATH = srcs/
OBJ_PATH = objs/
LIB_PATH = lib/libft/
INC_PATH = includes/
INC_LIBFT_PATH = lib/libft/includes/

##FILES
SRC_NAME =	ft_check.c ft_format.c ft_map.c ft_read.c ft_resolver.c main.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft

##VARIABLES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))
INC_LIBFT = $(addprefix -I,$(INC_LIBFT_PATH))
LIBFT = lib/libft/libft.a

.PHONY: all, clean, fclean, re

##RULES
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LIB) $(LIB_NAME) -o $(NAME) $^
	@echo "\n [$(NAME)] %.o\t\t\033[1;32m[Created]\033[0m"
	@echo " [$(NAME)] $(NAME)\t\033[1;32m[Created]\033[0m"

$(LIBFT):
	@make -C $(LIB_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) $(INC_LIBFT) -o $@ -c $<
	@echo "\033[32m████\033[0m\c"

clean:
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make clean -C $(LIB_PATH)
	@echo " [libft.a] %.o\t\t\033[1;34m[Removed]\033[0m"
	@echo " [$(NAME)] %.o\t\t\033[1;34m[Removed]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_PATH)
	@echo " [$(NAME)] $(NAME)\t\033[1;34m[Removed]\033[0m"

re: fclean all
