/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_move_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:56:20 by asando            #+#    #+#             */
/*   Updated: 2025/09/21 22:25:50 by asando           ###   ########.fr       */
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
		if (current->push_cost == 0)
			break ;
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

void	move_stack(t_stack **stack_1, t_stack **stack_2, t_op_flag flag)
{
	t_stack	*node_to_push;

	node_to_push = *stack_2;
	if (flag & PB)
	{
		node_to_push = find_to_push(stack_1);
		move(stack_1, stack_2, node_to_push);
		move_top_1(stack_1, stack_2, node_to_push);
		push(stack_1, stack_2, PB, 1);
	}
	else
	{
		move_top_2(stack_1, stack_2, node_to_push);
		push(stack_1, stack_2, PA, 1);
	}
}
