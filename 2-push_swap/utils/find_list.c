/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:49:11 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 11:07:38 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

t_list	*find_tail(t_list	*stack)
{
	while (stack->next->ordinal != -1)
		stack = stack->next;
	return (stack);
}

t_list	*find_max(t_list *stack)
{
	t_list	*max;

	max = stack->next;
	while (stack->next->ordinal != -1)
	{
		if (max->ordinal < stack->next->ordinal)
			max = stack->next;
		stack = stack->next;
	}
	return (max);
}

t_list	*find_ordinal(t_list *stack, ssize_t value)
{
	while (stack->next->ordinal != -1)
	{
		if (stack->ordinal == value)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
