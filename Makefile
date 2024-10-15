# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 22:22:39 by jurodrig          #+#    #+#              #
#    Updated: 2024/10/14 12:49:33 by jurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

###	Colors ###

GREEN 	=		\033[1;32m
RED		=		\033[0;31m
CYAN	=		\033[0;36m
WHITE	=		\033[0m

NAME	=	so_long

SRCS_DIR = srcs
OBJS_DIR = objs
LIBFT_DIR = libft
INC_DIR = inc
MAP_DIR = $(SRCS_DIR)/map

SRCS =	$(MAP_DIR)/read_map.c		\
		$(MAP_DIR)/init_file.c		\
		$(MAP_DIR)/validate_map.c	\

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lXext -lX11 -lm -lbsd
MLX_PATH = libft/libf.a
CFLAGS += -I $(INC_DIR) -I $(LIBFT_DIR)

all: $(NAME)

# Compilar el programa
$(NAME): objs $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -o $(NAME)
	@echo "$(GREEN)$(NAME) READY$(WHITE)"

objs:
	@mkdir -p $(OBJS_DIR)/$(SRCS_DIR) $(OBJS_DIR)/$(MAP_DIR)
# Regla para compilar archivos .c a .o
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

.PHONY: all clean fclean re
