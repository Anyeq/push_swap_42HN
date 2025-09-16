/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:25:06 by asando            #+#    #+#             */
/*   Updated: 2025/09/16 09:10:00 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_ps(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tail;

	first = *stack;
	second = NULL;
	tail = NULL;
	if (stack == NULL || *stack == NULL || (*stack)->next == *stack)
		return (-1);
	second = first->next;
	*stack = second;
	if ((*stack)->next == first)
		return (0);
	tail = first->prev;
	first->next = second->next;
	first->prev = second;
	tail->next = second;
	second->next->prev = first;
	second->next = first;
	second->prev = tail;
	return (0);
}

void	swap(t_stack **stack_1, t_stack **stack_2, t_op_flag flag, int p_out)
{
	int	swp_a;
	int	swp_b;

	swp_a = 1;
	swp_b = 1;
	if ((flag & SS) == SS)
	{
		ft_putstr_fd("Hello guys", 1);
		swp_a = swap_ps(stack_1);
		swp_b = swap_ps(stack_2);
		if ((swp_a == 0 || swp_b == 0) && p_out)
			ft_printf("ss\n");
	}
	else if (flag & SA)
	{
		if ((swap_ps(stack_1) == 0) && p_out)
			ft_printf("sa\n");
	}
	else if (flag & SB)
	{
		if ((swap_ps(stack_2) == 0) && p_out)
			ft_printf("sb\n");
	}
	return ;
}
