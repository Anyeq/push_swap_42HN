/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:12:15 by asando            #+#    #+#             */
/*   Updated: 2025/09/12 21:45:54 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack **stack_1, t_stack **stack_2, int direction)
{
	set_median_index(stack_1);
	set_median_index(stack_2);
	if (direction == 0)
	{
		set_target(stack_1, stack_2);
		set_push_cost(stack_2);
	}
	else
		set_target(stack_1, stack_2);
	return ;
}

static void	set_median_index(t_stack **stack)
{
	size_t	median;
	size_t	len_stack;
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	len_stack = stack_size(stack);
	median = len_stack / 2;
	while (current->next != *stack)
	{
		current->current_index = i;
		if (i <= median)
			current->above_median = 1;
		else
			current->above_median = 0;
		i++;
		current = current->next;
	}
	current->above_median = 0;
	return ;
}

static void	set_target_a(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*current_a;
	t_stack	*current_b;
	long	target_value;

	current_a = *stack_1;
	current_b = *stack_2;
	target_value = LONG_MIN;
	while (current_a->next != *stack_1)
	{
		while (current_b->next != *stack_2)
		{
			if (current_b->value > target_value && current_b->value < current_a->value)
			{
				target_value = current_b->value;
				current_a->target = current_b;
			}
			current_b = current_b->next;
		}
		if (current_b->value > target_value && current_b->value < current_a->value)
		{
			target_value = current_b->value;
			current_a->target = current_b;
		}
		if (target_value == LONG_MIN)
			current_a->target = max_value(stack_2);
		current_b = current_b->next;
		current_a = current_a->next;
	}
	return ;
}

static void	set_push_cost(t_stack **stack_1, t_stack **stack_2)
{
	size_t	len_stack_1;
	size_t	len_stack_2;
	t_stack	*current;

	current = *stack_1;
	len_stack_1 = stack_size(stack_1);
	len_stack_2 = stack_size(stack_2);
	while (current->next != *stack_1)
	{
		current->push_cost = current->current_index;
		if (current->above_median == 0)
			current->push_cost = len_stack_1 - current->current_index;
		if (current->target->above_median)
			current->push_cost += current->target->current_index;
		else if (current->target->above_median == 0)
			current->push_cost += len_stack_2 - current->target->current_index;
		current = current->next;
	}
	current->push_cost = len_stack_1 - current->current_index;
	if (current->target->above_median)
		current->push_cost += current->target->current_index;
	else if (current->target->above_median == 0)
		current->push_cost += len_stack_2 - current->target->current_index;
	return ;
}

t_stack	*find_to_push(t_stack **stack)
{
	t_stack	*cheapest_node;
	t_stack	*current;

	cheapest_node = *stack;
	current = *stack;
	cheapest = INT_MAX;
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
