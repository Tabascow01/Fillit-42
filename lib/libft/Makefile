##PROJECT
NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall

##DIRECTORIES
SRC_PATH = src/
OBJ_PATH = obj/
CPPFLAGS = -I includes

##FILES
SRC_NAME =	ft_set_lst.c ft_find_charset.c ft_strsplit_lst.c ft_putstr_fd.c\
			ft_strsplit_whitespaces_lst.c ft_strsplit_charset_lst.c ft_strclr.c\
			ft_print_words_table.c ft_strncmp.c ft_strsplit_charset.c ft_atoi.c\
			ft_strlen.c ft_strcmp.c ft_set_list.c ft_strcpy.c ft_putnbr_endl.c\
			ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_putchar_endl.c\
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_putnbr_fd.c ft_lstdelone.c\
			ft_itoa.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c\
			ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strdup.c ft_isalpha.c\
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
			ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
			ft_putstr.c ft_lstnew.c ft_lstdel.c ft_lstadd.c ft_putchar_fd.c\
			ft_lstiter.c ft_strrealloc.c ft_array_realloc.c ft_del_array.c\
			ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strsplit.c\
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
			ft_putendl_fd.c ft_memccpy.c ft_putendl.c ft_putchar.c ft_putnbr.c\
			ft_lstmap.c
			
OBJ_NAME =  $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

##RULES
.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"

$(NAME): $(OBJ)
	@ar rcus $@ $^
	@echo "\n [$(NAME)] %.o\t\t\033[1;32m[Created]\033[0m"
	@echo " [$(NAME)] $(NAME)\t\033[1;32m[Created]\033[0m"

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -f $(NAME)
	@echo " [$(NAME)] $(NAME)\t\033[1;34m[Removed]\033[0m"

re: fclean all
