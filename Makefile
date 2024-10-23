# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 22:22:39 by jurodrig          #+#    #+#              #
#    Updated: 2024/10/23 09:04:28 by jurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

#====================================Colors====================================#

GREEN 	=		\033[1;32m
RED		=		\033[0;31m
CYAN	=		\033[0;36m
WHITE	=		\033[0m

#===================================VARIABLES==================================#

NAME	=	so_long
LIBFT	=	$(LIBFT_DIR)libft.a
MLX			=	$(MLX_DIR)libmlx.a
MLX_LINUX	=	$(MLX_DIR)libmlx_linux.a

#===================================COMPILER===================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address $(IFLAGS)
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lXext -lX11 -lm -lbsd
IFLAGS += -I $(INC_DIR) -I $(LIBFT_DIR) $(MLX_DIR)

#=================================DIRECTORIES==================================#

SRCS_DIR	=	srcs
OBJS_DIR	=	objs
LIBFT_DIR	=	libft
INC_DIR	=	inc
MAIN_DIR	=	$(SRCS_DIR)/main
MAP_DIR	=	$(SRCS_DIR)/map
GAME_DIR	=	$(SRCS_DIR)/game
INPUT_DIR	=	$(SRCS_DIR)/input
RENDER_DIR	=	$(SRCS_DIR)/render

#===================================SOURCES====================================#

MAIN_SRCS	=	main.c 
MAP_SRCS =	init_file.c read_map.c validate_map.c
GAME_SRCS =	check.c init_game.c
INPUT_SRCS	=	input.c
RENDER_SRCS	=	render_map.c render_tile.c 

#====================================FILES=====================================#

SRCS =	$(addprefix $(GAME_DIR)/, $(GAME_SRCS))	\
		$(addprefix $(INPUT_DIR)/, $(MAIN_SRCS))	\
		$(addprefix $(MAP_DIR)/, $(MAP_SRCS))	\
		$(addprefix $(MAIN_DIR)/, $(MAIN_SRCS))	\
		$(addprefix $(RENDER_DIR)/, $(RENDER_SRCS))

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

#====================================Rules=====================================#

.PHONY: all clean fclean re

all: objs $(NAME)

# Compilar el programa
$(NAME): objs $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)$(NAME) program$(WHITE)"

objs:
	@mkdir -p $(OBJS_DIR)/$(SRCS_DIR) $(OBJS_DIR)/$(MAP_DIR) $(OBJS_DIR)/$(GAME_DIR) $(OBJS_DIR)/$(INPUT_DIR) $(OBJS_DIR)/$(RENDER_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling: $<"
# Limpiar los archivos objetos
clean:
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

