/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:34:45 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 20:52:03 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/push_swap.h"

void	push_swap(t_node *stack1, t_node *stack2, size_t size);

int	main(int ac, char *av[])
{
	t_node	*stack1;
	t_node	*stack2;

	stack1 = make_stack1(ac, av);
	stack2 = init_stack();
	push_swap(stack1, stack2, ac - 1);
	free_stack(stack1);
	free_stack(stack2);
	return (0);
}

void	push_swap(t_node *stack1, t_node *stack2, size_t size)
{
	if (is_sorted(stack1, ASC))
		return ;
	if (size <= 6)
		sort_short(stack1, stack2);
	else
		sort_long(stack1, stack2);
	return ;
}
