/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsb_radix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:59:59 by asando            #+#    #+#             */
/*   Updated: 2025/08/24 20:12:14 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*store_to_array(t_stack **stack)
{
	int	*arr_value;
	int	size;
	t_stack	*curr;
	int	i;

	i = 0;
	size = stack_size(*stack);
	curr = *stack;
	arr_value = malloc(sizeof(int) * size);
	if (arr_value == NULL)
		return (NULL);
	if (stack == NULL || *stack == NULL)
	{
		free(arr_value);
		return (NULL);
	}
	while (i < size)
	{
		arr_value[i++] = curr->value;
		curr = curr->next;
	}
	return (arr_value);
}

int	lsb_radix(t_stack **stack_1, t_stack **stack_2)
{
	return (0);
}
