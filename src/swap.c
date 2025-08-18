/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:25:06 by asando            #+#    #+#             */
/*   Updated: 2025/08/18 16:00:24 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ps(t_stack **stack, t_swap_flag flag)
{
	t_stack	*curr;

	curr = *stack;
	if (curr && curr->next && curr->next->next)
	{
		*stack = curr->next;
		curr->next = (*stack)->next;
		curr->next->prev = curr;
		curr->prev = *stack;
		(*stack)->next = curr;
		(*stack)->prev = NULL;
		if (flag & SA)
			ft_printf("sa\n");
		else if (flag & SB)
			ft_printf("sb\n");
	}
	return ;
}

void	swapss_ps(t_stack **stack_a, t_stack **stack_b)
{
	swap_ps(stack_a, SS);
	swap_ps(stack_b, SS);
	ft_printf("ss\n");
}
