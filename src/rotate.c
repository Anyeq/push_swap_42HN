/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:07:00 by asando            #+#    #+#             */
/*   Updated: 2025/08/21 17:05:36 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_a(t_stack **stack)
{
	if (stack == NULL && *stack == NULL && *stack->next == *stack)
		return (-1);
	*stack = (*stack)->next;
	return (0);
}

static int	rotate_b(t_stack **stack)
{
	if (stack == NULL && *stack == NULL && *stack->prev == *stack)
		return (-1);
	*stack = (*stack)->prev;
	return (0);
}

void	rotate_ps(t_stack **stack_1, t_stack **stack_2, t_op_flag flag)
{
	if (flag & RA)
	{
		if (rotate_a(stack_1) == 0)
			ft_printf("ra\n");
	}
	else if (flag & RB)
	{
		if (rotate_b(stack_2) == 0)
			ft_printf("rb\n");
	}
	else if (flag & RR)
	{
		int	rot_a;
		int	rot_b;

		rot_a = rotate_a(stack_1);
		rot_b = rotate_b(stack_2);
		if (rot_a == 0 || rot_b == 0)
			ft_printf("rr\n");
	}
	return ;
}
