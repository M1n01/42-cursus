/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:09:28 by minabe            #+#    #+#             */
/*   Updated: 2022/06/23 22:56:47 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	putnbr_hex(unsigned long long nbr, char conv);
int	put_str(char *s);
int	put_ptr(unsigned long long ptr);
int	ft_putchar(char c);
int	ft_putnbr(long long n);

#endif
