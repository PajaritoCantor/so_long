# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 22:22:39 by jurodrig          #+#    #+#              #
#    Updated: 2024/10/21 19:57:13 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

#==============================COLOURS============================================#

GREEN 	=		\033[1;32m
RED		=		\033[0;31m
CYAN	=		\033[0;36m
WHITE	=		\033[0m

#==============================DIRECTORIES============================================#

INC				:= inc/
SRCS_DIR		:= srcs/
OBJS_DIR		:= objs/
LIBFT_DIR		:= libft/
MLX_DIR			:= minilibx-linux/

MAP_DIR			:= map/
RENDER_DIR		:= render/
GRAFIC_DIR		:= grafic/
HOOK_DIR		:= hook/
UTILS_DIR		:= utils/
GAME_DIR		:= game/
GRAFIC_DIR		:= grafic/

#==============================VARIABLES=============================================#

NAME	= so_long
LIBFT	= $(LIBFT_DIR)libft.a
MLX		= $(MLX_DIR)libmlx.a
MLX_LINUX	= $(MLX_DIR)libmlx_Linux.a

#===============================COMPILER============================================#

CC		= gcc
CFLAGS	= -Wextra -Werror -Wall -g3 -fsanitize=address
LDFLAGS	= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX) $(MLX_LINUX) -lX11 -lXext -lm -lbsd
MKDIR	= mkdir -p
IFLAGS	= -I$(INC) -I$(LIBFT_DIR) -I$(MLX_DIR)

#==============================SOURCES============================================#

MAP_FILES		:= init_file read_map validate_map 
GAME_FILES		:= init_game main check
RENDER_FILES	:= render_tile
UTILS_FILES		:= check_ber
HOOK_FILES		:= 
GRAFIC_FILES	:=

# ==============================FILES============================================#

SRCS_FILES+=$(addprefix $(MAP_DIR), $(MAP_FILES))
SRCS_FILES+=$(addprefix $(RENDER_DIR), $(RENDER_FILES))
SRCS_FILES+=$(addprefix $(GRAFIC_DIR), $(GRAFIC_FILES))
SRCS_FILES+=$(addprefix $(HOOK_DIR), $(HOOK_FILES))
SRCS_FILES+=$(addprefix $(UTILS_DIR), $(UTILS_FILES))
SRCS_FILES+=$(addprefix $(GAME_DIR), $(GAME_FILES))

SRCS		:= $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS		:= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
DEPS		:= $(addprefix $(OBJS_DIR), $(addsuffix .d, $(SRCS_FILES)))

#==============================RULES=============================================#

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@$(MKDIR) $(dir $@)	
	@$(CC) $(CFLAGS) -I$(INC) -I$(LIBFT_DIR) -I$(MLX_DIR) -MP -MMD -c $< -o $@

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\n$(GREEN)$(NAME)✓ compiled!$(DEF_COLOR)"
	@echo "$(BOLD_CYAN)\n------------\n| Done! 👌 |\n------------$(DEF_COLOR)"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MLX):
	@make -sC $(MLX_DIR)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@make fclean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GREEN)$(NAME)$(YELLOW) cleaned$(DEF_COLOR)"

re: fclean all

-include $(DEPS)

.SILENT: all clean fclean
