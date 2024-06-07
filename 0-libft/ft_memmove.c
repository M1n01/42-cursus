/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:57:58 by minabe            #+#    #+#             */
/*   Updated: 2022/06/16 17:00:19 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*to;
	const unsigned char	*from;

	if (dst == NULL && src == NULL)
		return (NULL);
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	if (from < to)
	{
		while (len--)
			*(to + len) = *(from + len);
	}
	else
	{
		while (len--)
			*(to++) = *(from++);
	}
	return (dst);
}
