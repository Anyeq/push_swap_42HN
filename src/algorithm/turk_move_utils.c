/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:56:20 by asando            #+#    #+#             */
/*   Updated: 2025/09/16 08:48:12 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_to_push(t_stack **stack)
{
	t_stack	*cheapest_node;
	t_stack	*current;

	cheapest_node = *stack;
	current = *stack;
	if (cheapest_node->push_cost == 0)
		return (cheapest_node);
	while (current)
	{
		if (current->push_cost < cheapest_node->push_cost)
			cheapest_node = current;
		current = current->next;
		if (current == *stack)
			break ;
	}
	return (cheapest_node);
}

int	check_sorted_list(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	if (stack == NULL || *stack == NULL)
		return (-1);
	while (current->next != *stack)
	{
		if (current->value > (current->next)->value)
			return (-1);
		current = current->next;
	}
	return (0);
}

void	last_move(t_stack **stack)
{
	t_stack	*first;
	t_stack	*head;

	first = min_value(stack);
	head = *stack;
	while (first != head && first->above_midi)
	{
		rotate(stack, NULL, RA, 1);
		head = *stack;
	}
	while (first != head && first->above_midi == 0)
	{
		reverse_rotate(stack, NULL, RRA, 1);
		head = *stack;
	}
	return ;
}

static void	move_to_top(t_stack **stack_1, t_stack **stack_2,
						t_stack *node, int direction)
{
	if (direction == 1)
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
	else
	{
		while (node->target->above_midi && node->target != *stack_1)
			rotate(stack_1, stack_2, RA, 1);
		while (node->target->above_midi == 0
			&& node->target != *stack_1)
			reverse_rotate(stack_1, stack_2, RRA, 1);
	}
}

void	move_stack(t_stack **stack_1, t_stack **stack_2, t_op_flag flag)
{
	t_stack	*node_to_push;

	node_to_push = *stack_2;
	if (flag & PB)
	{
		node_to_push = find_to_push(stack_1);
		if (node_to_push->above_midi && node_to_push->target->above_midi)
		{
			while (node_to_push != *stack_1 && node_to_push->target != *stack_2)
				rotate(stack_1, stack_2, RR, 1);
		}
		else if (node_to_push->above_midi == 0
			&& node_to_push->target->above_midi == 0)
		{
			while (node_to_push != *stack_1 && node_to_push->target != *stack_2)
				reverse_rotate(stack_1, stack_2, RRR, 1);
		}
		move_to_top(stack_1, stack_2, node_to_push, 1);
		push(stack_1, stack_2, PB, 1);
	}
	else
	{
		move_to_top(stack_1, stack_2, node_to_push, 2);
		push(stack_1, stack_2, PA, 1);
	}
}
