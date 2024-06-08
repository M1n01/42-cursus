/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:28 by minabe            #+#    #+#             */
/*   Updated: 2022/06/23 22:30:30 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_str(char *s)
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
