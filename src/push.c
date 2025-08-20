/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:01:33 by asando            #+#    #+#             */
/*   Updated: 2025/08/20 22:12:42 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*pop_back(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tail;

	first = *stack;
	tail = NULL;
	if (stack == NULL && *stack == NULL)
		return (first);
	if ((first)->prev == *stack)
	{
		*stack = NULL;
		return (first);
	}
	*stack = first->prev;
	if ((*stack)->prev == first)
	{
		(*stack)->next = *stack;
		(*stack)->prev = *stack;
	}
	else
	{
		tail = first->next;
		(*stack)->next = tail;
		tail->prev = *stack;
	}
	return (first);
}

static t_stack	*pop_front(t_stack **stack)
{
	t_stack	*first;
	t_stack	*tail;

	first = *stack;
	tail = NULL;
	if (stack == NULL && *stack == NULL)
		return NULL;
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

static void	push_pa(t_stack **stack_1, t_stack **stack_2)
{
	t_stack *tail;
	t_stack	*to_pushed;

	to_pushed = pop_back(stack_2);
	tail = *stack_1;
	if (*stack_1 == NULL)
	{
		*stack_1 = to_pushed;
		(*stack_1)->next = to_pushed;
		(*stack_1)->prev = to_pushed;
	}
	else
	{
		tail = (*stack_1)->prev;
		to_pushed->next = *stack_1;
		to_pushed->prev = tail;
		tail->next = to_pushed;
		(*stack_1)->prev = to_pushed;
		*stack_1 = to_pushed;
	}
	ft_printf("pa\n");
}

static void	push_pb(t_stack **stack_1, t_stack **stack_2)
{
	t_stack *tail;
	t_stack	*to_pushed;

	to_pushed = pop_front(stack_1);
	tail = *stack_2;
	if (*stack_2 == NULL)
	{
		*stack_2 = to_pushed;
		(*stack_2)->next = to_pushed;
		(*stack_2)->prev = to_pushed;
	}
	else
	{
		tail = (*stack_2)->next;
		to_pushed->next = tail;
		to_pushed->prev = *stack_2;
		tail->prev = to_pushed;
		(*stack_2)->next = to_pushed;
		*stack_2 = to_pushed;
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
