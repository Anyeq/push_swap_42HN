/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:01:33 by asando            #+#    #+#             */
/*   Updated: 2025/08/25 16:21:52 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*pop_front(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tail;

	first = *stack;
	tail = NULL;
	if (stack == NULL || *stack == NULL)
		return (NULL);
	if ((first)->next == *stack)
	{
		*stack = NULL;
		return (first);
	}
	*stack = first->next;
	if ((*stack)->next == first)
	{
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
	}
	else
	{
		tail = first->prev;
		(*stack)->prev = tail;
		tail->next = *stack;
	}
	return (first);
}

static void	push_ps(t_stack **stack_dest, t_stack **stack_src)
{
	t_stack	*tail;
	t_stack	*to_pushed;

	to_pushed = pop_front(stack_src);
	tail = *stack_dest;
	if (to_pushed == NULL)
		return ;
	if (*stack_dest == NULL)
	{
		*stack_dest = to_pushed;
		(*stack_dest)->next = to_pushed;
		(*stack_dest)->prev = to_pushed;
	}
	else
	{
		tail = (*stack_dest)->prev;
		to_pushed->next = *stack_dest;
		to_pushed->prev = tail;
		tail->next = to_pushed;
		(*stack_dest)->prev = to_pushed;
		*stack_dest = to_pushed;
	}
	return ;
}

void	push(t_stack **stack_1, t_stack **stack_2, t_op_flag flag)
{
	if (flag & PA)
	{
		push_ps(stack_1, stack_2);
		ft_printf("pa\n");
	}
	else if (flag & PB)
	{
		push_ps(stack_2, stack_1);
		ft_printf("pb\n");
	}
	return ;
}

void	push_all(t_stack **stack_1, t_stack **stack_2, t_op_flag flag)
{
	t_stack	*curr;

	curr = *stack_1;
	if (flag & PA)
	{
		curr = *stack_2;
		while (stack_2 && curr && curr->next != *stack_2)
		{
			push(stack_1, stack_2, PA);
			curr = curr->next;
		}
		if (curr)
			push(stack_1, stack_2, PA);
	}
	else if (flag & PB)
	{
		while (stack_1 && curr && curr->next != *stack_1)
		{
			push(stack_1, stack_2, PB);
			curr = curr->next;
		}
		if (curr)
			push(stack_1, stack_2, PB);
	}
	return ;
}
