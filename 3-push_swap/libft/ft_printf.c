/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:08:27 by minabe            #+#    #+#             */
/*   Updated: 2023/02/22 00:07:55 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	put_conv(char *iter, va_list *ap);
static int	put_str(char *s);
static int	put_ptr(unsigned long long ptr);

int	ft_printf(const char *format, ...)
{
	int		res;
	char	*iter;
	va_list	ap;

	iter = (char *)format;
	if (!iter)
		return (0);
	res = 0;
	va_start(ap, format);
	while (*iter != '\0')
	{
		if (*iter == '%')
		{
			iter++;
			res += put_conv(iter, &ap);
			iter++;
			continue ;
		}
		res += ft_putchar(*iter);
		iter++;
	}
	va_end(ap);
	return (res);
}

static int	putnbr_hex(unsigned long long nbr, char conv)
{
	int	res;

	res = 0;
	if (nbr / 16 != 0)
		res += putnbr_hex(nbr / 16, conv);
	if ((nbr % 16) >= 10 && conv == 'x')
		res += ft_putchar((nbr % 16) - 10 + 'a');
	else if ((nbr % 16) >= 10 && conv == 'X')
		res += ft_putchar((nbr % 16) - 10 + 'A');
	else
		res += ft_putchar((nbr % 16) + '0');
	return (res);
}

static int	put_conv(char *iter, va_list *ap)
{
	if (*iter == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (*iter == 's')
		return (put_str(va_arg(*ap, char *)));
	else if (*iter == 'p')
		return (put_ptr((unsigned long long)va_arg(*ap, void *)));
	else if (*iter == 'd' || *iter == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (*iter == 'u')
		return (ft_putnbr(va_arg(*ap, unsigned int)));
	else if (*iter == 'x')
		return (putnbr_hex(va_arg(*ap, unsigned int), *iter));
	else if (*iter == 'X')
		return (putnbr_hex(va_arg(*ap, unsigned int), *iter));
	else if (*iter == '%')
		return (ft_putchar(*iter));
	return (0);
}

static int	put_str(char *s)
{
	size_t	i;
	int		res;

	if (!s)
		return (put_str("(null)"));
	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		res += ft_putchar(s[i]);
		i++;
	}
	return (res);
}

static int	put_ptr(unsigned long long ptr)
{
	int	res;

	res = 0;
	res += put_str("0x");
	return (res + putnbr_hex(ptr, 'x'));
}
