/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:09:31 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 20:24:58 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_realloc(void *p, size_t size)
{
	void	*new_data;

	new_data = NULL;
	if (size == 0)
		return (NULL);
	new_data = malloc(size);
	if (new_data == NULL)
		exit(1);
	if (p != NULL)
	{
		ft_memcpy(new_data, p, size);
		free(p);
	}
	return (new_data);
}
