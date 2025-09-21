/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_optimizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:27:03 by asando            #+#    #+#             */
/*   Updated: 2025/09/21 21:20:36 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move(t_stack **stack_1, t_stack **stack_2, t_stack *node)
{
	if (node->above_midi && node->target->above_midi)
	{
		while (node != *stack_1 && node->target != *stack_2)
			rotate(stack_1, stack_2, RR, 1);
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
		rotate(stack_1, stack_2, RA, 1);
	while (node->above_midi == 0 && node != *stack_1)
		reverse_rotate(stack_1, stack_2, RRA, 1);
	while (node->target->above_midi && node->target != *stack_2)
		rotate(stack_1, stack_2, RB, 1);
	while (node->target->above_midi == 0
		&& node->target != *stack_2)
		reverse_rotate(stack_1, stack_2, RRB, 1);
}

void	move_top_2(t_stack **stack_1, t_stack **stack_2, t_stack *node)
{
	while (node->target->above_midi && node->target != *stack_1)
		rotate(stack_1, stack_2, RA, 1);
	while (node->target->above_midi == 0
		&& node->target != *stack_1)
		reverse_rotate(stack_1, stack_2, RRA, 1);
}

void	push_cost_optimizer(t_stack **stack_1, t_stack **stack_2)
{
	int		len_stack_1;
	int		len_stack_2;
	t_stack	*current;
	int		target_push_cost;

	current = *stack_1;
	len_stack_1 = stack_size(stack_1);
	len_stack_2 = stack_size(stack_2);
	target_push_cost = 0;
	while (current)
	{
		current->push_cost = current->current_index;
		if (current->above_midi == 0)
			current->push_cost = len_stack_1 - current->current_index;
		current = current->next;
		if (current == *stack_1)
			break ;
	}
	return ;
}

void	push_cost_optimizer(t_stack *current, int node_push_cost,
						int target_push_cost)
{
	if (current->target->above_midi && current->above_midi)
	{
		if (current->current_index > current->target->current_index)
			current->push_cost += current->current_index
				- current->target->current_index;
		else
			current->push_cost += current->target->current_index
				- current->current_index;
	}
	else if (current->target->above_midi && current->above_midi == 0)
		current->push_cost += current->target->current_index;
	else if (current->target->above_midi == 0 && current->above_midi)
		current->push_cost += target_push_cost;
	else
	{
		if (current->push_cost > target_push_cost)
			current->push_cost += current->push_cost - target_push_cost;
		else
			current->push_cost += target_push_cost - current->push_cost;
	}
	return ;
}
