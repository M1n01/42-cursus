/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:14:49 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 11:22:45 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_atoi(const char *str);
void	ft_error(void *p);
void	ft_free(void *p);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putnbr(long long n);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *str1, char *str2);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
void	*ft_realloc(void *p, size_t size);
char	*get_next_line(int fd);

#endif
