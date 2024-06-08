/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 22:52:28 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 11:29:52 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

t_info	*init_info(void)
{
	size_t	i;
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		ft_error(info);
	info->turn = LIMIT_SHORT;
	info->tmp = malloc(sizeof(int) * (info->turn));
	if (info->tmp == NULL)
		ft_error(info->tmp);
	i = 0;
	while (i < info->turn)
	{
		info->tmp[i] = -1;
		i++;
	}
	info->ans = NULL;
	info->pre = -1;
	return (info);
}

t_info	*init_info_long_ver(void)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		ft_error(info);
	info->turn = 0;
	info->tmp = NULL;
	info->ans = NULL;
	info->pre = -1;
	return (info);
}

void	free_info(t_info *info)
{
	ft_free(info->tmp);
	ft_free(info->ans);
	ft_free(info);
}
