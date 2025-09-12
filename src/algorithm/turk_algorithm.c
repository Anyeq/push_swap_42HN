/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:33:57 by asando            #+#    #+#             */
/*   Updated: 2025/09/12 18:37:53 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

static void	sort_three(t_stack **stack_1, t_stack **stack_2)
{
	t_stack *current;

	current = *stack;
	if (max_nbr(stack_1) == *stack_1)
		rotate(stack_1, stack_2, RA);
	else if (max_nbr(stack_1) == (*stack)->next)
		reverse_rotate(stack_1, stack_2, RRA);
	if ((*stack)->value > (*stack)->next->value)
		swap(stack_1, stack_2, SA);
	return ;
}

static t_stack *max_nbr(t_stack **stack)
{
	t_stack *max;
	t_stack *current;

	current = *stack;
	max = *stack;
	while (current->next != *stack)
	{
		if (current->value > current->next->value)
			max = current;
		else
			max = current->next->value;
		current = current->next;
	}
	return (max);
}

static void	sort_stack(t_stack **stack_1, t_stack **stack_2)
{
	size_t	len_stack;

	len_stack = stack_size(*stack_1);
	if (len_stack-- > 3 && check_sorted_list(stack_1))
		push(stack_1, stack_2, PA);
	if (len_stack-- > 3 && check_sorted_list(stack_1))
		push(stack_1, stack_2, PA);
	while (len_stack-- > 3 && check_sorted_list(stack_1))
	{
		init_content_stack(stack_1, stack_2, len_stack);

	}
	sort_three(stack_1, stack_2, );
}

void	turk_algo(t_stack **stack_1, t_stack **stack_2)
{ 
	size_t	len_stack;

	len_stack = stack_size(*stack_1);
	//swap when it has two data only
	if (len_stack <= 3)
		short_three(stack_1, stack_2);
	if (len_stack > 3)
		sort_stack(stack_1, stack_2);
}
