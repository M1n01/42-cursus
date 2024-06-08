/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:40:25 by minabe            #+#    #+#             */
/*   Updated: 2023/04/25 16:04:20 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/push_swap.h"

void	top_sort(t_node *stack1, t_node *stack2, t_info *info)
{
	size_t	size;
	size_t	push_count;

	push_count = 0;
	size = stack_size(stack1) / 5;
	while (push_count < size)
	{
		record_command(stack1, stack2, info, RRA);
		pb_and_split_half(stack1, stack2, info, size / 2);
		push_count++;
	}
	pile_up_blocks(stack1, stack2, info, size);
}
