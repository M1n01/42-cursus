/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:53:52 by minabe            #+#    #+#             */
/*   Updated: 2022/06/15 09:54:57 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *str, size_t size);

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strnlen(dst, dstsize);
	if (dstlen == dstsize)
		return (dstsize + srclen);
	if (dstsize < srclen + dstlen + 1)
	{
		ft_memcpy(dst + dstlen, src, dstsize - dstlen - 1);
		dst[dstsize - 1] = '\0';
	}
	else
		ft_memcpy(dst + dstlen, src, srclen + 1);
	return (dstlen + srclen);
}

static size_t	ft_strnlen(char *str, size_t size)
{
	char	*p;

	p = ft_memchr(str, 0, size);
	if (p == NULL)
		return (size);
	else
		return (p - str);
}
