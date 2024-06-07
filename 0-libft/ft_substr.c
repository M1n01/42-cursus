/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 17:19:45 by minabe            #+#    #+#             */
/*   Updated: 2022/06/16 14:02:33 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;

	slen = ft_strlen(s);
	if (slen <= start)
		str = ft_strdup("");
	else
	{
		str = malloc(sizeof(char) * (slen - start + 1));
		if (!str)
			return (NULL);
		ft_strlcpy(str, s + start, len + 1);
	}
	return (str);
}
