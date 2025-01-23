# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 22:22:39 by jurodrig          #+#    #+#              #
#    Updated: 2025/01/22 01:02:15 by jurodrig         ###   ########.fr        #
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
INC_BONUS		:= inc_bonus/
LIBFT_DIR       := libft/
MLX_DIR         := minilibx-codam/
MLX_INCLUDE     := $(MLX_DIR)include/
MLX_BUILD       := $(MLX_DIR)build/

SRCS_DIR        := srcs/
OBJS_DIR        := objs/
GAME_DIR        := game/
CONTROL_DIR    	:= control/
MAIN_DIR        := main/
MAP_DIR         := map/

SRCS_BONUS_DIR	:= srcs_bonus/
OBJS_BONUS_DIR  := objs_bonus/
GAME_BONUS_DIR  := game_bonus/
CONTROL_BONUS_DIR  := control_bonus/
MAIN_BONUS_DIR  := main_bonus/
MAP_BONUS_DIR   := map_bonus/

#==============================VARIABLES=============================================#

NAME    = so_long
NAME_BONUS = so_long_bonus
LIBFT   = $(LIBFT_DIR)libft.a
MLX_LIB = $(MLX_BUILD)libmlx42.a

#===============================COMPILER============================================#

CC      = gcc
CFLAGS  = -Wextra -Werror -Wall -Wunreachable-code -Ofast -g3 #-fsanitize=address
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_BUILD) -lmlx42 -ldl -lglfw -lm
MKDIR   = mkdir -p
IFLAGS  = -I$(INC) -I$(INC_BONUS) -I$(LIBFT_DIR) -I$(MLX_INCLUDE)

#==============================SOURCES============================================#

GAME_FILES      := init_game render textures end_game free_textures
CONTROL_FILES  	:= keyboard
MAIN_FILES      := main
MAP_FILES       := read_map set_map_data utils_map validate_map valid_characters flood_fill path_validation

SRCS_FILES+=$(addprefix $(GAME_DIR), $(GAME_FILES))
SRCS_FILES+=$(addprefix $(CONTROL_DIR), $(CONTROL_FILES))
SRCS_FILES+=$(addprefix $(MAIN_DIR), $(MAIN_FILES))
SRCS_FILES+=$(addprefix $(MAP_DIR), $(MAP_FILES))

SRCS        := $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS        := $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
DEPS        := $(addprefix $(OBJS_DIR), $(addsuffix .d, $(SRCS_FILES)))

GAME_BONUS_FILES	:= init_game_bonus render_bonus textures_bonus end_game_bonus free_textures_bonus
CONTROL_BONUS_FILES := keyboard_bonus utils_control_bonus
MAIN_BONUS_FILES	:= main_bonus
MAP_BONUS_FILES		:= flood_fill_bonus path_validation_bonus read_map_bonus set_map_data_bonus utils_map_bonus valid_characters_bonus validate_map_bonus 

SRCS_BONUS_FILES+=$(addprefix $(GAME_BONUS_DIR), $(GAME_BONUS_FILES))
SRCS_BONUS_FILES+=$(addprefix $(CONTROL_BONUS_DIR), $(CONTROL_BONUS_FILES))
SRCS_BONUS_FILES+=$(addprefix $(MAIN_BONUS_DIR), $(MAIN_BONUS_FILES))
SRCS_BONUS_FILES+=$(addprefix $(MAP_BONUS_DIR), $(MAP_BONUS_FILES))

SRCS_BONUS := $(addprefix $(SRCS_BONUS_DIR), $(addsuffix .c, $(SRCS_BONUS_FILES)))
OBJS_BONUS := $(addprefix $(OBJS_BONUS_DIR), $(addsuffix .o, $(SRCS_BONUS_FILES)))
DEPS_BONUS := $(addprefix $(OBJS_BONUS_DIR), $(addsuffix .d, $(SRCS_BONUS_FILES)))

#==============================RULES=============================================#

.PHONY: all clean fclean re mlx_build

all: $(NAME)

bonus: $(NAME_BONUS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\n$(GREEN)$(NAME)✓ compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)\n------------\n| Ready! 👌 |\n------------$(DEF_COLOR)"

$(OBJS_BONUS_DIR)%.o: $(SRCS_BONUS_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -MP -MMD -c $< -o $@

$(NAME_BONUS): $(LIBFT) $(MLX_LIB) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(NAME_BONUS)
	@echo "\n$(GREEN)$(NAME)✓ compiled!$(DEF_COLOR)"
	@echo "$(RED)\n------------\n| Ready! 👌 |\n------------$(DEF_COLOR)"

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
	@$(RM) -rf $(OBJS_DIR) $(OBJS_BONUS_DIR)
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(YELLOW)Object files cleaned$(DEF_COLOR)"

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@rm -rf $(MLX_BUILD)
	@echo "$(GREEN)$(NAME) $(NAME_BONUS)$(YELLOW) fully cleaned$(DEF_COLOR)"

re: fclean all

-include $(DEPS)

.SILENT: all clean fclean
