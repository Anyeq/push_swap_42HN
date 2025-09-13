/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:33:57 by asando            #+#    #+#             */
/*   Updated: 2025/09/13 15:04:08 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_value(t_stack **stack)
{
	t_stack	*max;
	t_stack	*current;

	current = *stack;
	max = *stack;
	while (current->next != *stack)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	if (current->value > max->value)
		max = current;
	return (max);
}

t_stack	*min_value(t_stack **stack)
{
	t_stack	*min;
	t_stack	*current;

	current = *stack;
	min = *stack;
	while (current->next != *stack)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	if (current->value < min->value)
		min = current;
	return (min);
}

static void	sort_stack(t_stack **stack_1, t_stack **stack_2)
{
	size_t	len_stack;
	int		i;

	i = 0;
	len_stack = stack_size(stack_1);
	while (len_stack-- > 3 && check_sorted_list(stack_1))
	{
		if (i < 2)
			push(stack_1, stack_2, PA);
		else
		{
			init_stack(stack_1, stack_2, 0);
			move_stack(stack_1, stack_2, PB);
		}
	}
	sort_three(stack_1, stack_2, len_stack);
	while (*stack_2)
	{
		init_stack(stack_1, stack_2, 1);
		move_stack(stack_1, stack_2, PA);
	}
	set_middle_index(*stack_1);
}

static void	sort_three(t_stack **stack_1, t_stack **stack_2, size_t len)
{
	t_stack	*current;

	current = *stack;
	if (max_value(stack_1) == *stack_1)
		rotate(stack_1, stack_2, RA);
	else if (max_value(stack_1) == (*stack)->next && len >= 3)
		reverse_rotate(stack_1, stack_2, RRA);
	if ((*stack)->value > (*stack)->next->value)
		swap(stack_1, stack_2, SA);
	return ;
}

void	turk_algo(t_stack **stack_1, t_stack **stack_2)
{
	size_t	len_stack;

	len_stack = stack_size(*stack_1);
	//swap when it has two data only
	if (len_stack <= 3)
		short_three(stack_1, stack_2, len_stack);
	else
		sort_stack(stack_1, stack_2);
}
