/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:56:20 by asando            #+#    #+#             */
/*   Updated: 2025/09/13 13:58:56 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_to_push(t_stack **stack)
{
	t_stack	*cheapest_node;
	t_stack	*current;

	cheapest_node = *stack;
	current = *stack;
	while (current->next != *stack)
	{
		if (current->push_cost < cheapest_node->push_cost)
			cheapest_node = current;
		current = current->next;
	}
	if (current->push_cost < cheapest_node->push_cost)
		cheapest_node = current;
	return (cheapest_node);
}

static void	move_to_top(t_stack **stack_1, t_stack **stack_2, t_stack *node_to_push)
{
	while (node_to_push->above_midi && node_to_push != *stack_1)
		rotate(stack_1, stack_2, RA);
	while (node_to_push->above_midi == 0 && node_to_push != *stack_1)
		reverse_rotate(stack_1, stack_2, RRA);
	while (node_to_push->target->above_midi && node_to_push->target != *stack_2)
		rotate(stack_1, stack_2, RB);
	while (node_to_push->target->above_midi == 0 && node_to_push->target != *stack_2)
		reverse_rotate(stack_1, stack_2, RRB);
	return ;
}

//check if rotate update the while condition stack address
void	move_stack(t_stack **stack_1, t_stack **stack_2)
{
	t_stack *node_to_push;

	node_to_push = find_to_push(stack_1);
	if (node_to_push->above_midi && node_to_push->target->above_midi)
	{
		while (node_to_push != *stack_1 && node_to_push->target != *stack_2)
			rotate(stack_1, stack_2, RR);
	}
	else if (node_to_push->above_midi == 0 && node_to_push->target->above_midi == 0)
	{
		while (node_to_push != *stack_1 && node_to_push->target != *stack_2)
			reverse_rotate(stack_1, stack_2, RRR);
	}
	move_to_top(stack_1, stack_2, node_to_push);
	push(stack_1, stack_2, PB);
	return ;
}
