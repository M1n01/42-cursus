/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:34:15 by minabe            #+#    #+#             */
/*   Updated: 2023/06/18 22:11:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	get_start(char const *s1, char const *set);
static size_t	get_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end <= start)
		str = ft_strdup("");
	else
	{
		str = malloc(sizeof(char) * (end - start + 1));
		if (!str)
			ft_error("Malloc failed");
		ft_strlcpy(str, s1 + start, end - start + 1);
	}
	return (str);
}

static size_t	get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	return (i);
}

static size_t	get_end(char const *s1, char const *set)
{
	ssize_t	i;
	size_t	len;

	len = ft_strlen(s1);
	i = len - 1;
	while (i >= 0)
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i--;
	}
	return (i + 1);
}
