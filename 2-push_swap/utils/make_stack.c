/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 08:53:25 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 11:24:27 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	lstadd_tail(t_node *stack, int value, ssize_t coodinate);

t_node	*make_stack1(int ac, char *av[])
{
	int		*array;
	int		i;
	ssize_t	*coordinate;
	t_node	*stack;

	array = make_array(ac, av);
	coordinate = compression(array, ac - 1);
	stack = init_stack();
	i = 0;
	while (i < ac - 1)
	{
		lstadd_tail(stack, array[i], coordinate[i]);
		i++;
	}
	ft_free(array);
	ft_free(coordinate);
	return (stack);
}

t_node	*init_stack(void)
{
	t_node	*head;
	t_node	*stack;

	stack = malloc(sizeof(t_node));
	if (stack == NULL)
		ft_error(stack);
	head = stack;
	stack->prev = head;
	stack->value = 0;
	stack->ordinal = -1;
	stack->next = head;
	return (stack);
}

static void	lstadd_tail(t_node *stack, int value, ssize_t coodinate)
{
	t_node	*head;
	t_node	*tail;
	t_node	*new;

	head = stack;
	tail = find_tail(stack);
	new = malloc(sizeof(t_node));
	if (new == NULL)
		ft_error(new);
	new->value = value;
	new->ordinal = coodinate;
	new->next = head;
	new->prev = tail;
	tail->next = new;
	head->prev = new;
	return ;
}
