/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:37:15 by minabe            #+#    #+#             */
/*   Updated: 2022/06/14 21:07:22 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pmem;

	if (count * size == 0)
	{
		count = 1;
		size = 1;
	}
	if (count > INT_MAX / size)
		return (NULL);
	pmem = malloc(count * size);
	if (pmem == NULL)
		return (NULL);
	ft_memset(pmem, 0, count * size);
	return (pmem);
}
