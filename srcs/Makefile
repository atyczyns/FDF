NAME = fdf

CC = gcc
CCF = -fsanitize=address
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lmlx -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL \
            -framework AppKit
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEAD) -I$(MLX_HEAD)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./Libft/
LIBFT_HEAD = $(LIBFT_DIR)includes/

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = /usr/local/lib/
MLX_HEAD = $(MLX_DIR)/../include/mlx.h

HEADERS_LIST = fdf.h mlx_macro_keys.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_LIST = ft_init_map.c \
			ft_lst_map.c \
			keys_bind.c \
			lst_mlx.c \
			main.c \
			map.c \
			menu.c \
			mouv.c \
			read.c \
			tools.c \
			tools_2.c \
			coloring.c

SRC_DIR = ./srcs/
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))


YELLOW = \033[033m
GREEN = \033[032m
BLUE = \033[36m
RED = \033[031m
PURPLE = \033[35m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	@echo "$(YELLOW)Sources compilation $(RESET)[$(GREEN)OK$(RESET)]\n"
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "[$(BLUE)FDF Compiled$(RESET)]"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "\n$(BLUE)Obj directory...$(RESET)[$(GREEN)created$(RESET)]\n"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(YELLOW)$(notdir $(basename $@))...$(RESET)[$(GREEN)OK$(RESET)]"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "\n$(RED)Obj directory...$(RESET)[$(PURPLE)deleted$(RESET)]\n"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(RED)Libft...$(RESET)[$(PURPLE)deleted$(RESET)]\n"
	@rm -f $(NAME)
	@echo "$(RED)FDF...$(RESET)[$(PURPLE)deleted$(RESET)]\n"

sani :  $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	@echo "$(YELLOW)Sources compilation $(RESET)[$(GREEN)OK$(RESET)]\n"
	@$(CC) $(CCF) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "[$(BLUE)FDF Compiled$(RESET)]"
re:
	@$(MAKE) fclean
	@$(MAKE) all
