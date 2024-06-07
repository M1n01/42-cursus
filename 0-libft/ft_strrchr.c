/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:28:30 by minabe            #+#    #+#             */
/*   Updated: 2022/06/10 15:07:11 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	ssize_t	i;
	size_t	len;
	char	*str;
	char	to_find;

	str = (char *)s;
	to_find = (char)c;
	len = ft_strlen(str);
	if (to_find == '\0')
		return (str + len);
	i = len;
	while (i >= 0)
	{
		if (s[i] == to_find)
			return (str + i);
		i--;
	}
	return (NULL);
}
