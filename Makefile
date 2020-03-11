NAME	= fractol
SRC		= main_frac.c fracs.c extras.c
OBJ		= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
CC		= clang
FLAGS	= -Wall -Wextra -Werror -g -O3
MLX_LNK	= -L ./minilibx -l mlx -framework OpenGL -framework AppKit
FT		= ./libft/
FT_LIB	= libft.a
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft
SRC_DIR	= ./src/
INC_DIR	= ./includes/
OBJ_DIR	= ./obj/

all: obj $(FT_LIB) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(FLAGS) $(FT_INC) -I $(INC_DIR) -o $@ -c $<
	@echo "\033[1;34mFractol Compilation: $<\033[m"

$(FT_LIB):
	@make -C $(FT)
	@echo "\033[1;36mlibft Compiled\033[m"
	@echo "\033[1;31m-------------------------------------\033[m"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(FT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean

re: fclean all
