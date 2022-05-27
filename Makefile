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
	srcs/utils_2.c \
	srcs/texture.c \

SRC_BONUS = srcs_bonus/main_b.c \
	srcs_bonus/ft_split_cub_b.c \
	srcs_bonus/parser_b.c \
	srcs_bonus/parser_2_b.c \
	srcs_bonus/parser_3_b.c \
	srcs_bonus/deal_key_b.c \
	srcs_bonus/minimap_b.c \
	srcs_bonus/vision_b.c \
	srcs_bonus/movements_b.c \
	srcs_bonus/map3d_b.c \
	srcs_bonus/utils_b.c \
	srcs_bonus/utils_2_b.c \
	srcs_bonus/texture_b.c \


OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

BONUS = @$(CC) $(LDFLAG) $(FLAGS) $(OBJ_BONUS) libft/libft.a mlx/libmlx.a -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(LDFLAG) $(FLAGS) ${OBJ} libft/libft.a mlx/libmlx.a -o $(NAME)

clean:
	@make -C libft/ clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)

bonus : $(OBJ_BONUS)
	@make -C libft/
	@${BONUS}
re: fclean all
