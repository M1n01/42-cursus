/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:09:35 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 20:25:32 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;
	size_t	len;

	if (ft_strlen(str1) < ft_strlen(str2))
		len = ft_strlen(str1);
	else
		len = ft_strlen(str2);
	i = 0;
	while (i < len)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
