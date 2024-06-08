/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_middle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:40:25 by minabe            #+#    #+#             */
/*   Updated: 2023/04/25 16:03:56 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

static void	sep_into_three(t_list *s1, t_list *s2, t_info *info, size_t size)
{
	ssize_t	max;
	ssize_t	pivot1;
	ssize_t	pivot2;
	size_t	push_size;

	max = find_max(s2)->ordinal;
	pivot1 = max + 1 - size * 2 / 3;
	pivot2 = max + 1;
	push_size = 0;
	while (push_size < size * 2 / 3)
	{
		if (pivot1 <= s2->next->ordinal && s2->next->ordinal < pivot2)
		{
			pa_and_split_half(s1, s2, info, (pivot1 + pivot2) / 2);
			push_size++;
		}
		else
			record_command(s1, s2, info, RB);
	}
}

void	middle_sort(t_list *stack1, t_list *stack2, t_info *info, size_t size)
{
	ssize_t	max;
	ssize_t	pivot1;
	size_t	push_size;

	max = find_max(stack2)->ordinal;
	pivot1 = max + 1 - size * 2 / 3;
	sep_into_three(stack1, stack2, info, size);
	push_size = 0;
	while (push_size < size / 3)
	{
		pb_and_split_half(stack1, stack2, info, pivot1 + size / 2);
		push_size++;
	}
	pile_up_blocks(stack1, stack2, info, size / 3);
	push_size = 0;
	while (push_size < size / 3)
	{
		record_command(stack1, stack2, info, RRA);
		pb_and_split_half(stack1, stack2, info, pivot1 + size / 4);
		push_size++;
	}
	pile_up_blocks(stack1, stack2, info, size * 2 / 3);
}
