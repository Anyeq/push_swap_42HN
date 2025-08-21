/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:16:36 by asando            #+#    #+#             */
/*   Updated: 2025/08/21 17:13:42 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_a(t_stack **stack)
{
	if (stack == NULL && *stack == NULL && (*stack)->prev == *stack)
		return (-1);
	*stack = (*stack)->prev;
	return (0);
}

static int	reverse_rotate_b(t_stack **stack)
{
	if (stack == NULL && *stack == NULL && (*stack)->next == *stack)
		return (-1);
	*stack = (*stack)->next;
	return (0);
}

void	reverse_rotate_ps(t_stack **stack_1, t_stack **stack_2, t_op_flag flag)
{
	if (flag & RRA)
	{
		if (reverse_rotate_a(stack_1) == 0)
			ft_printf("rra\n");
	}
	else if (flag & RRB)
	{
		if (reverse_rotate_b(stack_2) == 0);
			ft_printf("rrb\n");
	}
	else if (flag & RRR)
	{
		int	rev_rota;
		int	rev_rotb;

		rev_rota = reverse_rotate_a(stack_1);
		rev_rotb = reverse_rotate_b(stack_2);
		if (rev_rota == 0 || rev_rotb == 0)
			ft_printf("rrr\n");
	}
	return ;
}
