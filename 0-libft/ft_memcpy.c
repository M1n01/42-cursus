/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:26:17 by minabe            #+#    #+#             */
/*   Updated: 2022/04/12 17:41:38 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*to;
	char	*from;

	to = (char *)dst;
	from = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return (dst);
}
