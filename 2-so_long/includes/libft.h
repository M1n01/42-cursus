/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:14:49 by minabe            #+#    #+#             */
/*   Updated: 2023/05/03 12:25:29 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include "../libft/ft_printf/ft_printf.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_error(char *str);
void	ft_free(void *p);

bool	ft_isalnum(int c);
bool	ft_isalpha(int c);
bool	ft_isascii(int c);
bool	ft_isdigit(int c);
bool	ft_isprint(int c);
char	*ft_itoa(int n);

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *buf, int ch, size_t n);

ssize_t	ft_putchar(char c);
ssize_t	ft_putendl(char *s);
ssize_t	ft_putnbr(long long n);
ssize_t	ft_putstr(char *s);

void	*ft_realloc(void *p, size_t size);

char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char *s1, char *s2);

size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strnlen(char *str, size_t size);
char	*ft_strnstr(const char *haystack, char *needle, size_t len);

char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_tolower(int c);
int		ft_toupper(int c);

char	*get_next_line(int fd);

#endif
