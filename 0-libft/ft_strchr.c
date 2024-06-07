/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:21:48 by minabe            #+#    #+#             */
/*   Updated: 2022/06/07 13:51:18 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	to_find;

	str = (char *)s;
	to_find = (char)c;
	i = 0;
	if (to_find == '\0')
	{
		while (s[i] != '\0')
			i++;
		return (str + i);
	}
	while (s[i] != '\0')
	{
		if (s[i] == to_find)
			return (str + i);
		i++;
	}
	return (NULL);
}
