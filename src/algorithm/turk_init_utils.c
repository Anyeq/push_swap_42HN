/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:12:15 by asando            #+#    #+#             */
/*   Updated: 2025/09/14 20:30:35 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_middle_index(t_stack **stack)
{
	int		middle_index;
	int		len_stack;
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	if (stack == NULL || *stack == NULL)
		return ;
	len_stack = stack_size(stack);
	middle_index = len_stack / 2;
	while (current)
	{
		current->current_index = i;
		if (i <= middle_index)
			current->above_midi = 1;
		else
			current->above_midi = 0;
		i++;
		current = current->next;
		if (current == *stack)
			break ;
	}
	return ;
}

static void	set_target_a(t_stack **stack_1, t_stack **stack_2, long target)
{
	t_stack	*curr_a;
	t_stack	*curr_b;

	curr_a = *stack_1;
	curr_b = *stack_2;
	while (curr_a)
	{
		while (curr_b)
		{
			if (curr_b->value > target && curr_b->value < curr_a->value)
			{
				target = curr_b->value;
				curr_a->target = curr_b;
			}
			curr_b = curr_b->next;
			if (curr_b == *stack_2)
				break ;
		}
		if (target == LONG_MIN)
			curr_a->target = max_value(stack_2);
		target = LONG_MIN;
		curr_a = curr_a->next;
		if (curr_a == *stack_1)
			break ;
	}
}

static void	set_target_b(t_stack **stack_1, t_stack **stack_2, long target)
{
	t_stack	*curr_a;
	t_stack	*curr_b;

	curr_a = *stack_1;
	curr_b = *stack_2;
	while (curr_b)
	{
		while (curr_a)
		{
			if (curr_a->value < target && curr_a->value > curr_b->value)
			{
				target = curr_a->value;
				curr_b->target = curr_a;
			}
			curr_a = curr_a->next;
			if (curr_a == *stack_1)
				break ;
		}
		if (target == LONG_MAX)
			curr_b->target = min_value(stack_1);
		target = LONG_MAX;
		curr_b = curr_b->next;
		if (curr_b == *stack_2)
			break ;
	}
}

static void	set_push_cost(t_stack **stack_1, t_stack **stack_2)
{
	int		len_stack_1;
	int		len_stack_2;
	t_stack	*current;

	current = *stack_1;
	len_stack_1 = stack_size(stack_1);
	len_stack_2 = stack_size(stack_2);
	while (current)
	{
		current->push_cost = current->current_index;
		if (current->above_midi == 0)
			current->push_cost = len_stack_1 - current->current_index;
		if (current->target->above_midi)
			current->push_cost += current->target->current_index;
		else if (current->target->above_midi == 0)
			current->push_cost += len_stack_2 - current->target->current_index;
		current = current->next;
		if (current == *stack_1)
			break ;
	}
	return ;
}

void	init_stack(t_stack **stack_1, t_stack **stack_2, int direction)
{
	set_middle_index(stack_1);
	set_middle_index(stack_2);
	if (direction == 1)
	{
		set_target_a(stack_1, stack_2, LONG_MIN);
		set_push_cost(stack_1, stack_2);
	}
	else
		set_target_b(stack_1, stack_2, LONG_MAX);
	return ;
}
