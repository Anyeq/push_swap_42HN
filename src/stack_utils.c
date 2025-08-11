/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:32:01 by asando            #+#    #+#             */
/*   Updated: 2025/08/11 13:12:50 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	stack_add_back(int content, t_stack **stack)
{
	t_stack	*new_node;

	new_node = stack_node(content);
	while (*stack && *stack->next && new_node)
		*stack = *stack->next;
	if (*stack && new_node)
	{
		*stack->next = new_node;
		new_node->prev = *stack;
	}
	else if (*stack == NULL && new_node)
		*stack = new_node;
	return ;
}

void	stack_add_front(int content, t_stack **stack)
{
	t_stack *new_node;

	new_node = stack_new(content);
	if (*stack == NULL && new_node)
		*stack = new_node;
	else if (*stack && new_node)
	{
		new_node->next = *stack;
		*stack->prev = new_node;
		*stack = new_node;
	}
	return ;
}

void	stack_clean(t_stack **stack)
{
	t_stack *curr;
	t_stack *to_delete;

	curr = *stack;
	to_delete = curr;
	while (curr)
	{
		to_delete = curr;
		curr = curr->next;
		free(to_delete);
	}
	*stack = curr;
	return ;
}
