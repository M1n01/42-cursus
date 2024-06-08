/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:43:42 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 21:38:03 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/push_swap.h"

int ch_cmd(int cmd)
{
	if (cmd == PA)
		return (PB);
	if (cmd == PB)
		return (PA);
	if (cmd == RA)
		return (RRA);
	if (cmd == RB)
		return (RRB);
	if (cmd == RR)
		return (RRR);
	if (cmd == RRA)
		return (RA);
	if (cmd == RRB)
		return (RB);
	if (cmd == RRR)
		return (RR);
	return (cmd);
}

bool exec_cmd(t_node *stack1, t_node *stack2, int cmd)
{
	if (cmd == SA && stack_size(stack1) > 1)
		return (swap(stack1), true);
	if (cmd == SB && stack_size(stack2) > 1)
		return (swap(stack2), true);
	if (cmd == SS && stack_size(stack1) > 1 && stack_size(stack2) > 1)
		return (swap(stack1), swap(stack2), true);
	if (cmd == PA && stack_size(stack2) > 0)
		return (push(stack2, stack1), true);
	if (cmd == PB && stack_size(stack1) > 0)
		return (push(stack1, stack2), true);
	if (cmd == RA && stack_size(stack1) > 1)
		return (rotate(stack1), true);
	if (cmd == RB && stack_size(stack2) > 1)
		return (rotate(stack2), true);
	if (cmd == RR && stack_size(stack1) > 1 && stack_size(stack2) > 1)
		return (rotate(stack1), rotate(stack2), true);
	if (cmd == RRA && stack_size(stack1) > 1)
		return (rev_rotate(stack1), true);
	if (cmd == RRB && stack_size(stack2) > 1)
		return (rev_rotate(stack2), true);
	if (cmd == RRR && stack_size(stack1) > 1 && stack_size(stack2) > 1)
		return (rev_rotate(stack1), rev_rotate(stack2), true);
	return (false);
}

void command(t_node *stack1, t_node *stack2, int command)
{
	if (command == SA || command == SS)
		swap(stack1);
	if (command == SB || command == SS)
		swap(stack2);
	if (command == PA)
		push(stack2, stack1);
	if (command == PB)
		push(stack1, stack2);
	if (command == RA || command == RR)
		rotate(stack1);
	if (command == RB || command == RR)
		rotate(stack2);
	if (command == RRA || command == RRR)
		rev_rotate(stack1);
	if (command == RRB || command == RRR)
		rev_rotate(stack2);
}

void print_command(int cmd)
{
	if (cmd == SA)
		ft_printf("sa\n");
	if (cmd == SB)
		ft_printf("sb\n");
	if (cmd == SS)
		ft_printf("ss\n");
	if (cmd == RA)
		ft_printf("ra\n");
	if (cmd == RB)
		ft_printf("rb\n");
	if (cmd == RR)
		ft_printf("rr\n");
	if (cmd == RRA)
		ft_printf("rra\n");
	if (cmd == RRB)
		ft_printf("rrb\n");
	if (cmd == RRR)
		ft_printf("rrr\n");
	if (cmd == PA)
		ft_printf("pa\n");
	if (cmd == PB)
		ft_printf("pb\n");
}
