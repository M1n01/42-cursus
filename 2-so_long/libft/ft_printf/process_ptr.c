/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:50:02 by minabe            #+#    #+#             */
/*   Updated: 2022/06/23 22:36:46 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ptr(unsigned long long ptr)
{
	int	res;

	res = 0;
	res += put_str("0x");
	return (res + putnbr_hex(ptr, 'x'));
}
