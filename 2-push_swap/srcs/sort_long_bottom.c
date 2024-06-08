/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:40:25 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 20:48:05 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/push_swap.h"

static void	pb_seperate_bottom(t_node *stack1, t_node *stack2, t_info *info)
{
	size_t	size;
	ssize_t	pivot;

	size = stack_size(stack1);
	pivot = (ssize_t)size * 9 / 4;
	while (stack_size(stack1) > size / 2)
	{
		if (stack1->next->ordinal < (ssize_t)size / 2)
			record_command(stack1, stack2, info, RA);
		else
			pb_and_split_half(stack1, stack2, info, pivot);
	}
}

void	bottom_sort(t_node *stack1, t_node *stack2, t_info *info)
{
	size_t	size;

	pb_seperate_bottom(stack1, stack2, info);
	size = stack_size(stack1);
	while (stack_size(stack1) < size * 2)
		find_max_and_pa(stack1, stack2, info);
}
