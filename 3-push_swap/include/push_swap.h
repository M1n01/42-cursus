/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:44:37 by minabe            #+#    #+#             */
/*   Updated: 2023/04/24 21:27:18 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./libft.h"
# include "./utils.h"

# define LIMIT_SHORT 12
# define ASC 1
# define DESC 2

void	push_swap(t_list *stack1, t_list *stack2, size_t size);
void	sort_short(t_list *stack1, t_list *stack2);
void	dfs(t_list *stack1, t_list *stack2, t_info *info, size_t turn);
void	update_ans(t_info *info, size_t turn);

void	sort_long(t_list *stack1, t_list *stack2);
void	bottom_sort(t_list *stack1, t_list *stack2, t_info *info);
void	middle_sort(t_list *stack1, t_list *stack2, t_info *info, size_t size);
void	top_sort(t_list *stack1, t_list *stack2, t_info *info);

#endif