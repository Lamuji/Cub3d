NAME = cub3d

CC = cc
FLAGS =  -g -Wall -Wextra -Werror 
LDFLAG = -Lmlx -framework OpenGL -framework AppKit

SRC = srcs/main.c \
	srcs/ft_split_cub.c \
	srcs/parser.c \
	srcs/parser_2.c \
	srcs/parser_3.c \
	srcs/deal_key.c \
	srcs/minimap.c \
	srcs/vision.c \
	srcs/movements.c \
	srcs/map3d.c \
	srcs/utils.c \
	srcs/texture.c \

OBJ = $(SRC:%.c=%.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(LDFLAG) $(FLAGS) $^ -o $@ libft/libft.a mlx/libmlx.a

clean:
	@make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)
	
re: fclean all