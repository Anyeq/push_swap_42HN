/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:13:16 by asando            #+#    #+#             */
/*   Updated: 2025/09/12 15:21:58 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef enum e_op_flag
{
	SA = 1 << 0,
	SB = 1 << 1,
	SS = SA || SB,
	PA = 1 << 2,
	PB = 1 << 3,
	RA = 1 << 4,
	RB = 1 << 5,
	RR = RA || RB,
	RRA = 1 << 6,
	RRB = 1 << 7,
	RRR = RRA || RRB
}	t_op_flag;

//main function
int		grab_arg(int n_arg, char **s, t_stack **stack);

//stack utils function
t_stack	*stack_new(int content);
void	stack_clean(t_stack **stack);
size_t	stack_size(t_stack **stack);
int		stack_add_back(int content, t_stack **stack);

//operation function
void	swap(t_stack **stack_1, t_stack **stack_2, t_op_flag flag);
void	push(t_stack **stack_1, t_stack **stack_2, t_op_flag flag);
void	push_all(t_stack **stack_1, t_stack **stack_2, t_op_flag flag);
void	rotate(t_stack **stack_1, t_stack **stack_2, t_op_flag flag);
void	reverse_rotate(t_stack **stack_1, t_stack **stack_2, t_op_flag flag);

//algorithm function
int		radix(t_stack **stack_1, t_stack **stack_2);

#endif
