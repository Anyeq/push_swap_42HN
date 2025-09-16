/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:07:00 by asando            #+#    #+#             */
/*   Updated: 2025/09/16 09:13:07 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_ps(t_stack **stack)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == *stack)
		return (-1);
	*stack = (*stack)->next;
	return (0);
}

void	rotate(t_stack **stack_1, t_stack **stack_2, t_op_flag flag, int p_out)
{
	int	rot_a;
	int	rot_b;

	rot_a = 1;
	rot_b = 1;
	if ((flag & RR) == RR)
	{
		rot_a = rotate_ps(stack_1);
		rot_b = rotate_ps(stack_2);
		if ((rot_a == 0 || rot_b == 0) && p_out)
			ft_printf("rr\n");
	}
	else if (flag & RA)
	{
		if (rotate_ps(stack_1) == 0 && p_out)
			ft_printf("ra\n");
	}
	else if (flag & RB)
	{
		if ((rotate_ps(stack_2) == 0) && p_out)
			ft_printf("rb\n");
	}
	return ;
}
