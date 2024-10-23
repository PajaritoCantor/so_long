# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 19:52:46 by jurodrig          #+#    #+#              #
#    Updated: 2024/10/23 17:59:50 by danpalac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB     =   ar -rcs
RM      =   rm -rf
CC      =   gcc
CFLAGS  =   -Wall -Wextra -Werror
NAME    =   libft.a

OBJS_DIR  =   objs/

SRCS    =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
        	ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_calloc.c \
            	ft_memcpy.c ft_memmove.c ft_memcmp.c ft_memchr.c \
            	ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
            	ft_strdup.c ft_substr.c ft_strtrim.c ft_strmapi.c ft_striteri.c \
            	ft_strlcat.c ft_strlcpy.c \
            	ft_strjoin.c ft_atoi.c ft_atoi_limits.c ft_isspace.c ft_itoa.c ft_split.c \
            	ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
            	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
            	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
            	ft_printf.c ft_printf_fd_utils.c ft_putnbr_base.c \
		get_next_line.c ft_print_error.c
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)

$(OBJS_DIR)%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

all:		$(NAME)

re: 		fclean all


