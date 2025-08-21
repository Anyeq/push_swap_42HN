/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:25:06 by asando            #+#    #+#             */
/*   Updated: 2025/08/21 17:03:53 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_a(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tail;

	first = *stack;
	second = NULL;
	tail = NULL;
	if (stack == NULL && *stack == NULL && (*stack)->next == *stack)
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

static int	swap_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tail;

	first = *stack;
	second = NULL;
	tail = NULL;
	if (stack == NULL && *stack == NULL && (*stack)->prev == *stack)
		return (-1);
	second = first->prev;
	*stack = second;
	if ((*stack)->prev == first)
		return (0);
	tail = first->next;
	first->prev = second->prev;
	first->next = second;
	second->next = tail;
	second->prev->next = first;
	second->prev = first;
	tail->prev = second;
	return (0);
}

void	swap_ps(t_stack **stack_1, t_stack **stack_2, t_op_flag flag)
{
	if (flag & SA)
	{
		if (swap_pa(stack_1) == 0)
			ft_printf("sa\n");
	}
	else if (flag & SB)
	{
		if (swap_pb(stack_2) == 0)
			ft_printf("sb\n");
	}
	else if (flag & SS)
	{
		int	swp_a;
		int	swp_b;

		swp_a = swap_a(stack_1);
		swp_b = swap_b(stack_2);
		if (swp_a == 0 && swp_b == 0)
			ft_printf("ss\n");
	}
	return ;
}
