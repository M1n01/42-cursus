/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:05:46 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 11:24:01 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"
#include "../include/push_swap.h"

static void sort(int *array, size_t size);
static void int_swap(int *big, int *small);
static void rank(int *array, int *array_cp, ssize_t *coordinate, size_t size);

int *make_array(int ac, char *av[])
{
	int i;
	int *array;

	array = malloc(sizeof(int) * (ac - 1));
	if (array == NULL)
		ft_error(array);
	i = 0;
	while (i < ac - 1)
	{
		array[i] = ft_atoi(av[i + 1]);
		i++;
	}
	return (array);
}

ssize_t *compression(int *array, size_t size)
{
	size_t i;
	ssize_t *coordinate;
	int *array_cp;

	array_cp = malloc(sizeof(int) * (size));
	if (array_cp == NULL)
		ft_error(array_cp);
	coordinate = malloc(sizeof(size_t) * (size));
	if (coordinate == NULL)
		ft_error(coordinate);
	i = 0;
	while (i < size)
	{
		array_cp[i] = array[i];
		i++;
	}
	sort(array_cp, size);
	rank(array, array_cp, coordinate, size);
	ft_free(array_cp);
	return (coordinate);
}

static void sort(int *array, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				ft_error(array);
			if (array[i] > array[j])
				int_swap(array + i, array + j);
			j++;
		}
		i++;
	}
	return;
}

static void int_swap(int *big, int *small)
{
	int tmp;

	tmp = *big;
	*big = *small;
	*small = tmp;
	return;
}

static void rank(int *array, int *array_cp, ssize_t *coordinate, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[i] == array_cp[j])
				coordinate[i] = j;
			j++;
		}
		i++;
	}
	return;
}
