/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:01:33 by asando            #+#    #+#             */
/*   Updated: 2025/08/23 16:25:26 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static t_stack	*pop_back(t_stack **stack)
//{
//	t_stack	*first;
//	t_stack	*tail;
//
//	first = *stack;
//	tail = NULL;
//	if (stack == NULL || *stack == NULL)
//		return (first);
//	if ((first)->prev == *stack)
//	{
//		*stack = NULL;
//		return (first);
//	}
//	*stack = first->prev;
//	if ((*stack)->prev == first)
//	{
//		(*stack)->next = *stack;
//		(*stack)->prev = *stack;
//	}
//	else
//	{
//		tail = first->next;
//		(*stack)->next = tail;
//		tail->prev = *stack;
//	}
//	return (first);
//}

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

//static void	push_a(t_stack **stack_1, t_stack **stack_2)
//{
//	t_stack	*tail;
//	t_stack	*to_pushed;
//
//	to_pushed = pop_back(stack_2);
//	tail = *stack_1;
//	if (to_pushed == NULL)
//		return ;
//	if (*stack_1 == NULL)
//	{
//		*stack_1 = to_pushed;
//		(*stack_1)->next = to_pushed;
//		(*stack_1)->prev = to_pushed;
//	}
//	else
//	{
//		tail = (*stack_1)->prev;
//		to_pushed->next = *stack_1;
//		to_pushed->prev = tail;
//		tail->next = to_pushed;
//		(*stack_1)->prev = to_pushed;
//		*stack_1 = to_pushed;
//	}
//	ft_printf("pa\n");
//	return ;
//}

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

//static void	push_b(t_stack **stack_1, t_stack **stack_2)
//{
//	t_stack	*tail;
//	t_stack	*to_pushed;
//
//	to_pushed = pop_front(stack_1);
//	tail = *stack_2;
//	if (to_pushed == NULL)
//		return ;
//	if (*stack_2 == NULL)
//	{
//		*stack_2 = to_pushed;
//		(*stack_2)->next = to_pushed;
//		(*stack_2)->prev = to_pushed;
//	}
//	else
//	{
//		tail = (*stack_2)->next;
//		to_pushed->next = tail;
//		to_pushed->prev = *stack_2;
//		tail->prev = to_pushed;
//		(*stack_2)->next = to_pushed;
//		*stack_2 = to_pushed;
//	}
//	ft_printf("pb\n");
//	return ;
//}

void	push(t_stack **stack_1, t_stack **stack_2, t_op_flag flag)
{
	if (flag & PA)
	{
		push_ab(stack_1, stack_2);
		ft_printf("pa\n");
	}
	else if (flag & PB)
	{
		push_ab(stack_2, stack_1);
		ft_printf("pb\n");
	}
	return ;
}
