/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:46:15 by minabe            #+#    #+#             */
/*   Updated: 2024/04/10 14:47:56 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret;
	int my_ret;

	ret = printf("Hello, %s\n", "world");
	my_ret = ft_printf("Hello, %s\n", "world");

	printf("ret = %d\n", ret);
	printf("my_ret = %d\n", my_ret);
	return (0);
}
