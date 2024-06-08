/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:45:56 by minabe            #+#    #+#             */
/*   Updated: 2023/04/30 17:36:23 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	to_find;

	if (s == NULL)
		return (NULL);
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
