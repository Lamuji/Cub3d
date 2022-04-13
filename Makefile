 
CC = gcc

AR = ar -rcs

FLAGS = -Wall -Wextra -Werror
LDFLAG = -lmlx -framework OpenGL -framework AppKit

NAME = cub3d

SRC = srcs/main.c \
	srcs/ft_split_cub.c \
	srcs/parser.c \
	srcs/parser_2.c \
	srcs/parser_3.c \
	srcs/deal_key.c \
	srcs/minimap.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(FLAGS) $(LDFLAG) $^ -o $@ libft/libft.a

clean:
	@make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)
	
re: fclean all