/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:23:40 by asando            #+#    #+#             */
/*   Updated: 2025/09/12 16:43:42 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted_list(t_stack **stack)
{
	t_stack *current;

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
