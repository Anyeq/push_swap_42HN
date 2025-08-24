/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:32:01 by asando            #+#    #+#             */
/*   Updated: 2025/08/23 17:23:23 by asando           ###   ########.fr       */
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

size_t	stack_size(t_stack **stack)
{
	size_t	size;
	t_stack	*curr;

	size = 0;
	curr = *stack;
	if (stack == NULL || *stack == NULL)
		return (0);
	while (curr->next != *stack)
	{
		size++;
		curr = curr->next;
	}
	size++;
	return (size);
}

static int	check_double(int content, t_stack **stack, t_stack **new_node)
{
	t_stack	*curr;

	curr = *stack;
	while (curr->next != *stack)
	{
		if (curr->value == content)
		{
			free(*new_node);
			return (-1);
		}
		curr = curr->next;
	}
	if (curr && curr->value == content)
	{
		free(*new_node);
		return (-1);
	}
	return (0);
}

int	stack_add_back(int content, t_stack **stack)
{
	t_stack	*new_node;
	t_stack	*tail;

	new_node = stack_new(content);
	tail = *stack;
	if (!new_node)
		return (-1);
	if (tail == NULL)
	{
		*stack = new_node;
		(*stack)->next = new_node;
		(*stack)->prev = new_node;
	}
	else
	{
		if (check_double(content, stack, &new_node) == -1)
			return (-1);
		tail = (*stack)->prev;
		new_node->next = *stack;
		new_node->prev = tail;
		tail->next = new_node;
		(*stack)->prev = new_node;
	}
	return (0);
}

void	stack_clean(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*to_delete;

	curr = *stack;
	to_delete = curr;
	while (curr && curr->next != *stack)
	{
		to_delete = curr;
		curr = curr->next;
		free(to_delete);
	}
	if (curr)
		free(curr);
	*stack = NULL;
	return ;
}
