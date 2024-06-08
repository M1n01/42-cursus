/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:15:51 by minabe            #+#    #+#             */
/*   Updated: 2023/04/30 17:37:05 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strnlen(char *str, size_t size)
{
	char	*p;

	p = ft_memchr(str, 0, size);
	if (p == NULL)
		return (size);
	else
		return (p - str);
}
