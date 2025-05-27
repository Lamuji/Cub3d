# Cross-platform Cub3D Makefile
NAME = cub3d

# Detect operating system
UNAME_S := $(shell uname -s)

CC = cc
FLAGS = -g -Wall -Wextra -Werror -Iincl

# Platform-specific settings
ifeq ($(UNAME_S), Darwin)
	# macOS settings
	MLX_DIR = mlx_macos
	FLAGS += -I$(MLX_DIR)
	LDFLAG = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	MLX_LIB = $(MLX_DIR)/libmlx.a
	PLATFORM_MSG = "Compiling for macOS"
else ifeq ($(UNAME_S), Linux)
	# Linux settings
	MLX_DIR = mlx
	FLAGS += -I$(MLX_DIR)
	LDFLAG = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
	MLX_LIB = $(MLX_DIR)/libmlx.a
	PLATFORM_MSG = "Compiling for Linux"
else
	# Default to Linux settings for other Unix-like systems
	MLX_DIR = mlx
	FLAGS += -I$(MLX_DIR)
	LDFLAG = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
	MLX_LIB = $(MLX_DIR)/libmlx.a
	PLATFORM_MSG = "Compiling for Unix-like system (using Linux settings)"
endif

SRC = srcs/main.c \
	srcs/utils/ft_split_cub.c \
	srcs/parser.c \
	srcs/parser_2.c \
	srcs/parser_3.c \
	srcs/deal_key.c \
	srcs/minimap.c \
	srcs/vision.c \
	srcs/movements.c \
	srcs/map3d.c \
	srcs/utils/utils.c \
	srcs/utils/utils_2.c \
	srcs/texture.c \

SRC_BONUS = srcs_bonus/main_b.c \
	srcs_bonus/utils/ft_split_cub_b.c \
	srcs_bonus/parser_b.c \
	srcs_bonus/parser_2_b.c \
	srcs_bonus/parser_3_b.c \
	srcs_bonus/deal_key_b.c \
	srcs_bonus/minimap_b.c \
	srcs_bonus/vision_b.c \
	srcs_bonus/movements_b.c \
	srcs_bonus/map3d_b.c \
	srcs_bonus/utils/utils_b.c \
	srcs_bonus/utils/utils_2_b.c \
	srcs_bonus/texture_b.c \


OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: platform_info $(NAME)

platform_info:
	@echo $(PLATFORM_MSG)

$(NAME): $(OBJ) $(MLX_LIB)
	@make -C libft/
	@$(CC) $(FLAGS) ${OBJ} libft/libft.a $(LDFLAG) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully for $(UNAME_S)"

# Build MLX library based on platform
$(MLX_LIB):
ifeq ($(UNAME_S), Darwin)
	@echo "🔨 Setting up macOS MLX library..."
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "📁 Creating macOS MLX directory..."; \
		mkdir -p $(MLX_DIR); \
		if [ -d "mlx_macos_backup" ]; then \
			cp -r mlx_macos_backup/* $(MLX_DIR)/; \
		else \
			echo "❌ macOS MLX backup not found. Please ensure mlx_macos_backup directory exists."; \
			exit 1; \
		fi; \
	fi
	@make -C $(MLX_DIR)
else
	@echo "🔨 Building Linux MLX library..."
	@make -C $(MLX_DIR)
endif

clean:
	@make -C libft/ clean
ifeq ($(UNAME_S), Darwin)
	@if [ -d "$(MLX_DIR)" ]; then make -C $(MLX_DIR) clean; fi
else
	@make -C $(MLX_DIR) clean
endif
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)

bonus: platform_info $(OBJ_BONUS) $(MLX_LIB)
	@make -C libft/
	@$(CC) $(FLAGS) $(OBJ_BONUS) libft/libft.a $(LDFLAG) -o $(NAME)
	@echo "✅ $(NAME) (bonus) compiled successfully for $(UNAME_S)"

re: fclean all

.PHONY: all clean fclean bonus re platform_info
