/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:35:33 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 11:11:23 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/push_swap.h"

void rotate_min_steps(t_node *stack, long step, char which, t_info *info)
{
	if (step >= 0)
	{
		while (step--)
		{
			if (which == 'A')
				record_command(stack, NULL, info, RA);
			if (which == 'B')
				record_command(NULL, stack, info, RB);
		}
	}
	else
	{
		while (step++)
		{
			if (which == 'A')
				record_command(stack, NULL, info, RRA);
			if (which == 'B')
				record_command(NULL, stack, info, RRB);
		}
	}
}

static ssize_t count_rotate(t_node *stack, t_node *find)
{
	size_t step;

	if (find == NULL)
		return (-1);
	step = 0;
	while (stack->next != find)
	{
		stack = stack->next;
		step++;
	}
	return (step);
}

static ssize_t count_rev_rotate(t_node *stack, t_node *find)
{
	size_t step;

	if (find == NULL)
		return (-1);
	step = 0;
	while (stack != find)
	{
		stack = stack->prev;
		step++;
	}
	return (step);
}

long cal_steps(t_node *stack, t_node *find)
{
	long rotate;
	long rev_rotate;

	rotate = count_rotate(stack, find);
	rev_rotate = count_rev_rotate(stack, find);
	if (rotate <= rev_rotate)
		return (rotate);
	else
		return (-rev_rotate);
}
