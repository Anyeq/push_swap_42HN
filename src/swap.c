/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:25:06 by asando            #+#    #+#             */
/*   Updated: 2025/08/20 21:13:15 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_pa(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tail;

	first = *stack;
	second = NULL;
	tail = NULL;
	if (stack && *stack && (*stack)->next == *stack)
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

static int	swap_pb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tail;

	first = *stack;
	second = NULL;
	tail = NULL;
	if (stack && *stack && (*stack)->prev == *stack)
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

void	swap_ps(t_stack **stack_1, t_stack **stack_2, t_swap_flag flag)
{
	if ((flag & SA) && swap_pa(stack_1) == 0)
		ft_printf("sa\n");
	else if ((flag & SB) && swap_pb(stack_2) == 0)
		ft_printf("sb\n");
	else if ((flag & SS) && swap_pa(stack_1) == 0 && swap_pb(stack_2) == 0)
		ft_printf("ss\n");
}
