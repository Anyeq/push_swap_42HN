/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_optimizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:27:03 by asando            #+#    #+#             */
/*   Updated: 2025/09/18 17:04:54 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	should_swap(t_stack **stack, t_stack *node)
{
	if (node->prev == *stack && (*stack)->value > node->value)
		return (1);
	return (0);
}

void	move(t_stack **stack_1, t_stack **stack_2, t_stack *node)
{
	if (node->above_midi && node->target->above_midi)
	{
		while (node != *stack_1 && node->target != *stack_2)
		{
			if (should_swap(stack_1, node)
				&& should_swap(stack_2, node->target))
				swap(stack_1, stack_2, SS);
			else
				rotate(stack_1, stack_2, RR, 1);
		}
	}
	else if (node->above_midi == 0
		&& node->target->above_midi == 0)
	{
		while (node != *stack_1 && node->target != *stack_2)
			reverse_rotate(stack_1, stack_2, RRR, 1);
	}
	return ;
}

void	move_top_1(t_stack **stack_1, t_stack **stack_2, t_stack *node)
{
	while (node->above_midi && node != *stack_1)
	{
		if (should_swap(stack_1, node))
			swap(stack_1, stack_2, SA);
		else
			rotate(stack_1, stack_2, RA, 1);
	}
	while (node->above_midi == 0 && node != *stack_1)
		reverse_rotate(stack_1, stack_2, RRA, 1);
	while (node->target->above_midi && node->target != *stack_2)
	{
		if (should_swap(stack_2, node->target))
			swap(stack_1, stack_2, SB);
		else
			rotate(stack_1, stack_2, RB, 1);
	}
	while (node->target->above_midi == 0
		&& node->target != *stack_2)
		reverse_rotate(stack_1, stack_2, RRB, 1);
}

void	move_top_2(t_stack **stack_1, t_stack **stack_2, t_stack *node)
{
	while (node->target->above_midi && node->target != *stack_1)
	{
		if (should_swap(stack_1, node->target))
			swap(stack_1, stack_2, SA);
		else
			rotate(stack_1, stack_2, RA, 1);
	}
	while (node->target->above_midi == 0
		&& node->target != *stack_1)
		reverse_rotate(stack_1, stack_2, RRA, 1);
}
