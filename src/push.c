/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:01:33 by asando            #+#    #+#             */
/*   Updated: 2025/08/18 21:32:14 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_pa(t_stack **stack_1, t_stack **stack_2)
{
	t_stack *curr;

	curr = *stack_2;
	*stack_2 = (*stack_2)->prev;
	if (*stack_2)
		*stack_2->next = NULL;
	if (*stack_1 == NULL)
	{
		*stack_1 = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else if (*stack_1 != NULL)
	{
		*stack_1->prev = curr;
		curr->next = *stack_1;
		curr->prev = NULL;
		*stack_1 = curr;
	}
	ft_printf("pa\n");
}

static void	push_pb(t_stack **stack_1, t_stack **stack_2)
{
	t_stack *curr;

	curr = *stack_1;
	*stack_1 = (*stack_1)->next;
	if (*stack_1)
		*stack_1->prev = NULL;
	if (*stack_2 == NULL)
	{
		*stack_2 = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else
	{
		*stack_2->next = curr;
		curr->next = NULL;
		curr->prev = *stack_2;
		*stack_2 = curr;
	}
	ft_printf("pb\n");
}

void	push_ps(t_stack **stack_1, t_stack **stack_2, t_push_flag flag)
{
	if ((flag & PA) && *stack_2)
		push_pa(stack_1, stack_2);
	else if ((flag & PB) && *stack_1)
		push_pb(stack_1, stack_2);
	return ;
}
