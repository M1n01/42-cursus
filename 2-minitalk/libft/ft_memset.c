/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:10:06 by minabe            #+#    #+#             */
/*   Updated: 2023/04/25 10:43:14 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*buf_set;

	buf_set = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		buf_set[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}
