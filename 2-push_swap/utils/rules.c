/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:05:10 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 20:53:06 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/utils.h"
#include "../include/push_swap.h"

void	swap(t_list *stack)
{
	t_list	*src;

	src = stack->next;
	lstcpy(src, src->next);
	lstdelone_node(src);
	return ;
}

void	push(t_list *from, t_list *to)
{
	t_list	*src;

	src = from->next;
	lstcpy(src, to);
	lstdelone_node(src);
	return ;
}

void	rotate(t_list *stack)
{
	t_list	*src;

	src = stack->next;
	lstcpy(src, stack->prev);
	lstdelone_node(src);
	return ;
}

void	rev_rotate(t_list *stack)
{
	t_list	*src;

	src = stack->prev;
	lstcpy(src, stack);
	lstdelone_node(src);
	return ;
}
