/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:33:57 by asando            #+#    #+#             */
/*   Updated: 2025/09/16 09:13:40 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_value(t_stack **stack)
{
	t_stack	*max;
	t_stack	*current;

	current = *stack;
	max = *stack;
	if (stack == NULL || *stack == NULL)
		return (NULL);
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
	if (stack == NULL || *stack == NULL)
		return (NULL);
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

static void	sort_three(t_stack **stack, size_t len)
{
	t_stack	*max;

	max = max_value(stack);
	if (max == *stack)
		rotate(stack, NULL, RA, 1);
	else if (max == (*stack)->next && len == 3)
		reverse_rotate(stack, NULL, RRA, 1);
	if ((*stack)->value > (*stack)->next->value)
		swap(stack, NULL, SA, 1);
	return ;
}

static void	sort_stack(t_stack **stack_1, t_stack **stack_2, int len_stack)
{
	int		i;

	i = 0;
	while (len_stack-- > 3 && check_sorted_list(stack_1) == -1)
	{
		if (i < 2)
			push(stack_1, stack_2, PB, 1);
		else
		{
			init_stack(stack_1, stack_2, 1);
			move_stack(stack_1, stack_2, PB);
		}
		i++;
	}
	if (len_stack == 3 && check_sorted_list(stack_1) == -1)
		sort_three(stack_1, len_stack);
	while (*stack_2)
	{
		init_stack(stack_1, stack_2, 2);
		move_stack(stack_1, stack_2, PA);
	}
	set_middle_index(stack_1);
	last_move(stack_1);
	return ;
}

int	turk_algo(t_stack **stack_1, t_stack **stack_2)
{
	int	len_stack;

	len_stack = stack_size(stack_1);
	if (len_stack && len_stack <= 3)
		sort_three(stack_1, len_stack);
	else if (len_stack)
		sort_stack(stack_1, stack_2, len_stack);
	if (check_sorted_list(stack_1) == 0)
		return (0);
	return (-1);
}
