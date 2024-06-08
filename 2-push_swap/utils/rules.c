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

#include "../include/utils.h"
#include "../include/push_swap.h"

void swap(t_node *stack)
{
	t_node *src;

	src = stack->next;
	lstcpy(src, src->next);
	lstdelone_node(src);
	return;
}

void push(t_node *from, t_node *to)
{
	t_node *src;

	src = from->next;
	lstcpy(src, to);
	lstdelone_node(src);
	return;
}

void rotate(t_node *stack)
{
	t_node *src;

	src = stack->next;
	lstcpy(src, stack->prev);
	lstdelone_node(src);
	return;
}

void rev_rotate(t_node *stack)
{
	t_node *src;

	src = stack->prev;
	lstcpy(src, stack);
	lstdelone_node(src);
	return;
}
