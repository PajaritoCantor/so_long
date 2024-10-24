/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:35:12 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 14:00:23 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# if BUFFER_SIZE > 125000 || BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif 

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdarg.h>
# include <signal.h>
# include <sys/time.h>

// Funciones de Verificación de Caracteres
int		ft_isalpha(int i);
int		ft_isdigit(int i);
int		ft_isalnum(int i);
int		ft_isascii(int i);
int		ft_isprint(int i);
int		ft_isspace(int c);
// Funciones de Transformación de Caracteres
int		ft_toupper(int i);
int		ft_tolower(int i);

// Funciones de Conversión de Caracteres
int		ft_atoi(const char *str);
int		ft_atoi_limits(const char *s);
char	*ft_itoa(int n);

// Funciones de Manipulación de Cadenas
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strjoin_gnl(char *s1, char *s2, int *eol_loc);
char	*ft_strdup(const char *s1);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	**ft_split(const char *s, char c);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);
 void	*ft_free_strs(char **strs);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// Funciones de Memoria
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);

// Funciones de Entrada y Salida
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

int		ft_printf(const char *string, ...);
int		ft_printfd(int fd, char const *string, ...);
int		ft_putchar_printf(int fd, int c);
int		ft_putstr_printf(int fd, char *str);
int		ft_strlen_printf(char *str);

int		ft_putnbr_base(int fd, unsigned long nbr, char *b);
int		ft_putnbr(int fd, int n);
int		ft_pointer(int fd, void *p);
// minitalk functions

int	ft_error(char *error_msg, int y);
int	ft_success(char *msg, int y);
// Funciones de Listas Enlazadas
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// Funciones de Get Next Line
char	*get_next_line(int fd);
char	*read_and_extract_line(char *line, char *stash, int *eol_loc, int fd);
char	*init_stash_line(char *stash, int *eol_loc);
size_t	find_eol_position(char *line);

#endif // LIBFT_H
