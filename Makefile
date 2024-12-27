# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 22:22:39 by jurodrig          #+#    #+#              #
#    Updated: 2024/12/26 16:06:09 by jurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#==============================COLOURS============================================#

GREEN       = \033[1;32m
RED         = \033[0;31m
CYAN        = \033[0;36m
WHITE       = \033[0m
DEF_COLOR   = \033[0m
BOLD_CYAN   = \033[1;36m
YELLOW      = \033[1;33m

#==============================DIRECTORIES============================================#

INC             := inc/
SRCS_DIR        := srcs/
OBJS_DIR        := objs/
LIBFT_DIR       := libft/
MLX_DIR         := minilibx-codam/
MLX_INCLUDE     := $(MLX_DIR)include/
MLX_BUILD       := $(MLX_DIR)build/

GAME_DIR        := game/
HOOK_DIR        := hook/
MAIN_DIR        := main/
MAP_DIR         := map/
RENDER_DIR      := render/
UTILS_DIR       := utils/
GRAFIC_DIR      := grafic/

#==============================VARIABLES=============================================#

NAME    = so_long
LIBFT   = $(LIBFT_DIR)libft.a
MLX_LIB = $(MLX_BUILD)libmlx42.a

#===============================COMPILER============================================#

CC      = gcc
CFLAGS  = -Wextra -Werror -Wall -g3 -fsanitize=address
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_BUILD) -lmlx42 -ldl -lglfw -pthread -lm
MKDIR   = mkdir -p
IFLAGS  = -I$(INC) -I$(LIBFT_DIR) -I$(MLX_INCLUDE)

#==============================SOURCES============================================#

GAME_FILES      := init_game
HOOK_FILES      := 
MAIN_FILES      := main
MAP_FILES       := read_map set_map_data utils_map validate_map flood_fill path_validation
RENDER_FILES    := 
GRAFIC_FILES    := 

SRCS_FILES+=$(addprefix $(GAME_DIR), $(GAME_FILES))
SRCS_FILES+=$(addprefix $(HOOK_DIR), $(HOOK_FILES))
SRCS_FILES+=$(addprefix $(MAIN_DIR), $(MAIN_FILES))
SRCS_FILES+=$(addprefix $(MAP_DIR), $(MAP_FILES))
SRCS_FILES+=$(addprefix $(RENDER_DIR), $(RENDER_FILES))
SRCS_FILES+=$(addprefix $(GRAFIC_DIR), $(GRAFIC_FILES))

SRCS        := $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS        := $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
DEPS        := $(addprefix $(OBJS_DIR), $(addsuffix .d, $(SRCS_FILES)))

#==============================RULES=============================================#

.PHONY: all clean fclean re mlx_build

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\n$(GREEN)$(NAME)✓ compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)\n------------\n| Ready! 👌 |\n------------$(DEF_COLOR)"

$(LIBFT):
	@if [ ! -f $@ ]; then make -sC $(LIBFT_DIR); fi

$(MLX_LIB): mlx_build

mlx_build:
	@if [ ! -f $(MLX_LIB) ]; then \
		echo "$(CYAN)Building MLX42 library...$(DEF_COLOR)"; \
		cmake -S $(MLX_DIR) -B $(MLX_BUILD) > /dev/null; \
		cmake --build $(MLX_BUILD) > /dev/null; \
	fi

clean:
	@$(RM) -rf $(OBJS_DIR)
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(YELLOW)Object files cleaned$(DEF_COLOR)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(MLX_BUILD)
	@echo "$(GREEN)$(NAME)$(YELLOW) fully cleaned$(DEF_COLOR)"

re: fclean all

-include $(DEPS)

.SILENT: all clean fclean

