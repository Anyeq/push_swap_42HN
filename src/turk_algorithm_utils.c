/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 18:12:15 by asando            #+#    #+#             */
/*   Updated: 2025/09/12 18:54:38 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	init_content_stack(t_stack **stack_1, t_stack **stack_2,
						size_t len_stack, int direction)
{
	if (direction == 0)
	{
		set_median_index(stack_1);
		set_target(stack_1, stack_2);
		set_push_cost(stack_2);
		set_cheapest(stack_1);

	}
	else //the other way around from b to a change the parameter
	{
		set_median_index(stack_1);
		set_target(stack_1, stack_2);
		set_push_cost(stack_2);
		set_cheapest(stack_1);
	}
	return ;
}

static void	set_median_index(t_stack **stack_1, size_t len_stack)
{
	size_t	median;
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack_1;
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
			current_a->target = max_nbr(stack_2);
		current_b = current_b->next;
		current_a = current_a->next;
	}
	return ;
}
