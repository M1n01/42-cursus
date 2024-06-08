/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 23:21:44 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 11:14:02 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/push_swap.h"

void find_max_and_pa(t_node *stack1, t_node *stack2, t_info *info)
{
	t_node *max;
	long step;

	max = find_max(stack2);
	if (max == NULL)
		return;
	step = cal_steps(stack2, max);
	rotate_min_steps(stack2, step, 'B', info);
	record_command(stack1, stack2, info, PA);
}

void pb_and_split_half(t_node *s1, t_node *s2, t_info *info, ssize_t piv)
{
	record_command(s1, s2, info, PB);
	if (s2->next->ordinal < piv)
		record_command(s1, s2, info, RB);
}

void pa_and_split_half(t_node *s1, t_node *s2, t_info *info, ssize_t piv)
{
	record_command(s1, s2, info, PA);
	if (s1->next->ordinal < piv)
		record_command(s1, s2, info, RA);
}

void pile_up_blocks(t_node *s1, t_node *s2, t_info *info, size_t size)
{
	size_t push_size;

	push_size = 0;
	while (push_size < size)
	{
		find_max_and_pa(s1, s2, info);
		push_size++;
	}
}
