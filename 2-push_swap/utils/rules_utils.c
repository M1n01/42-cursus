/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:54:43 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 11:29:29 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/push_swap.h"

t_node *lstdelone_node(t_node *trash)
{
	t_node *prev;

	prev = trash->prev;
	trash->next->prev = prev;
	prev->next = trash->next;
	ft_free(trash);
	return (prev->next);
}

void lstcpy(t_node *src, t_node *dest)
{
	t_node *new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		ft_error(new);
	new->value = src->value;
	new->ordinal = src->ordinal;
	new->prev = dest;
	new->next = dest->next;
	dest->next->prev = new;
	dest->next = new;
	return;
}
