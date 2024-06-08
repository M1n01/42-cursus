/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:18:24 by minabe            #+#    #+#             */
/*   Updated: 2023/04/25 11:12:07 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

ssize_t	ft_putendl(char *s)
{
	ssize_t	size;

	size = ft_putstr(s);
	size += write(1, "\n", 1);
	return (size);
}
