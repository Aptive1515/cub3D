/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:56:04 by tdelauna          #+#    #+#             */
/*   Updated: 2022/08/24 17:52:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

typedef struct s_list
{
	int				*content;
	int				f_place;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_atoi(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *first, const char *second, size_t length);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(const char *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_doubletab_len(char **tab);
int		ft_free_doubletab(char **tab);

/*
GNL------------------------------------------------------------------------------
*/
char	*get_next_line(int fd);
char	*ft_readline(int fd, char *buf_rest);
char	*ft_lign_print(char *buf_rest);
char	*ft_rest(char *buf_rest);
size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *str, int c);

/*
Printf---------------------------------------------------------------------------
*/
int		ft_printf(const char *format, ...);
int		ft_parse(char format, va_list args);
int		ft_arg_str(char *str);
int		ft_arg_unsigned(long int nbr);
char	*ft_strchr_print(char *s, int c);
int		ft_putchar_fd_print(char c, int fd);
int		ft_putstr_fd_print(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_putnbr_fd_print(long int n, int fd);
int		ft_putnbr_base_print(unsigned int nbr, char *base);
int		ft_am(unsigned long nbr, char *base);

#endif
