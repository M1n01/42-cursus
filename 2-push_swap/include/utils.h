/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:11:08 by minabe            #+#    #+#             */
/*   Updated: 2023/04/26 11:22:56 by minabe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include "../../0-libft/libft.h"

typedef struct s_node
{
	int				value;
	ssize_t			ordinal;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_info
{
	size_t	turn;
	int		*tmp;
	int		*ans;
	int		pre;
}			t_info;

typedef enum e_cmd
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}				t_cmd;

t_node	*make_stack1(int ac, char *av[]);
int		*make_array(int ac, char *av[]);
ssize_t	*compression(int *array, size_t	size);
t_node	*init_stack(void);
t_node	*find_tail(t_node	*stack);

void	swap(t_node *stack);
void	push(t_node *from, t_node *to);
void	rotate(t_node *stack);
void	rev_rotate(t_node *stack);

t_node	*lstdelone_node(t_node *trash);
void	lstcpy(t_node *src, t_node *dest);
size_t	stack_size(t_node *stack);

void	print_command(int command);
bool	is_sorted(t_node *stack, int order);
void	print_ans(t_info *info);
int		ch_cmd(int command);
bool	exec_cmd(t_node *stack1, t_node *stack2, int command);
bool	is_detour(int cmd, t_info *info);

t_info	*init_info(void);
t_info	*init_info_long_ver(void);
void	free_info(t_info *cmd);

long	cal_steps(t_node *stack, t_node *find);
void	rotate_min_steps(t_node *stack, long step, char which, t_info *info);

t_node	*find_ordinal(t_node *stack, ssize_t value);
t_node	*find_max(t_node *stack);

void	command(t_node *stack1, t_node *stack2, int command);
int		*add_ans(t_info *info, int command);
void	record_command(t_node *stack1, t_node *stack2, t_info *info, int cmd);

void	free_stack(t_node *stack);
void	ans_optimize(t_info *info);

void	find_max_and_pa(t_node *stack1, t_node *stack2, t_info *info);

void	pa_and_split_half(t_node *s1, t_node *s2, t_info *info, ssize_t piv);
void	pb_and_split_half(t_node *s1, t_node *s2, t_info *info, ssize_t piv);
void	pile_up_blocks(t_node *s1, t_node *s2, t_info *info, size_t size);

#endif
