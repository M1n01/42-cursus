/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:21:58 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 11:29:15 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/push_swap.h"

void print_ans(t_info *info)
{
	size_t i;

	i = 0;
	while (i < info->turn)
	{
		print_command(info->ans[i]);
		i++;
	}
}

int *add_ans(t_info *info, int command)
{
	int *ans;

	ans = malloc(sizeof(int) * (info->turn + 1));
	if (!ans)
		ft_error(ans);
	ft_memcpy(ans, info->ans, info->turn);
	ans[info->turn] = command;
	info->turn++;
	info->pre = command;
	ft_free(info->ans);
	return (ans);
}

bool check_delete(t_info *info, int cmd)
{
	if ((cmd == RA && info->pre == RRA) || (cmd == RRA && info->pre == RA) ||
		(cmd == RB && info->pre == RRB) || (cmd == RRB && info->pre == RB) ||
		(cmd == RR && info->pre == RRR) || (cmd == RRR && info->pre == RR) ||
		(cmd == SA && info->pre == SA) || (cmd == SB && info->pre == SB) ||
		(cmd == SS && info->pre == SS) || (cmd == PA && info->pre == PB) ||
		(cmd == PB && info->pre == PA))
		return (true);
	return (false);
}

void record_command(t_node *stack1, t_node *stack2, t_info *info, int cmd)
{
	command(stack1, stack2, cmd);
	if (check_delete(info, cmd))
	{
		info->pre = -1;
		info->turn--;
	}
	else if ((cmd == RA && info->pre == RB) || (cmd == RB && info->pre == RA))
	{
		info->ans[info->turn - 1] = RR;
		info->pre = RR;
	}
	else if ((cmd == RRA && info->pre == RRB) ||
			 (cmd == RRB && info->pre == RRA))
	{
		info->ans[info->turn - 1] = RRR;
		info->pre = RRR;
	}
	else if ((cmd == SA && info->pre == SB) || (cmd == SB && info->pre == SA))
	{
		info->ans[info->turn - 1] = SS;
		info->pre = SS;
	}
	else
		info->ans = add_ans(info, cmd);
}

void ans_optimize(t_info *info)
{
	size_t i;

	i = 0;
	while (i < info->turn - 1)
	{
		if ((info->ans[i - 1] == RA && info->ans[i] == PB) &&
			(info->ans[i] == PB && info->ans[i + 1] == RRA))
		{
			info->ans[i - 1] = SA;
			ft_memcpy(info->ans + i + 1, info->ans + i + 2, info->turn - i - 2);
			info->turn--;
		}
		if ((info->ans[i - 1] == RB && info->ans[i] == PA) &&
			(info->ans[i] == PA && info->ans[i + 1] == RRB))
		{
			info->ans[i - 1] = SB;
			ft_memcpy(info->ans + i + 1, info->ans + i + 2, info->turn - i - 2);
			info->turn--;
		}
		i++;
	}
}
