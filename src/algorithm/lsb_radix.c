/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsb_radix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:59:59 by asando            #+#    #+#             */
/*   Updated: 2025/08/25 17:30:47 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*store_to_array(t_stack **stack, int len_stack)
{
	int		*arr_value;
	t_stack	*curr;
	int		i;

	i = 0;
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

static int	binary_search(int *arr, int len, int target)
{
	int	mid;
	int	left;
	int	right;

	left = 0;
	right = len - 1;
	mid = 0;
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (arr[mid] == target)
			return (mid);
		else if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

static int	add_index(int *arr, t_stack **stack, int len)
{
	t_stack	*curr;
	int		*arr;
	int		idx;

	idx = 0;
	arr = store_to_array(stack_1);
	curr = *stack;
	if (arr != NULL && merge_sort(arr, 0, len - 1) == 0)
	{
		while (stack && curr && curr->next != *stack)
		{
			idx = binary_search(arr, len, curr->value);
			curr->index = idx;
			curr = curr->next;
		}
		if (curr)
			idx = binary_search(arr, len, curr->value);
		free(arr);
	}
	else
	{
		free(arr);
		return (-1);
	}
	return (0);
}

static void	lsb_radix(t_stack **stack_1, t_stack **stack_2, int bit_len,
	int len_stack)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < bit_len)
	{
		while (j < len_stack)
		{
			if ((curr->index & (1 << i)) == 0)
				push(stack_1, stack_2, PB);
			else
				rotate(stack_1, stack_2, RA);
			curr = curr->next;
			j++;
		}
		push_all(stack_1, stack_2, PA);
		curr = *stack_1;
		i++;
	}
	return ;
}

int	radix(t_stack **stack_1, t_stack **stack_2)
{
	int		len_stack;
	int		bit_len;
	t_stack	*curr;
	int		max_index;

	curr = *stack_1;
	len_stack = stack_size(stack_1);
	bit_len = 0;
	max_index = len_stack;
	while (max_index > 0)
	{
		bit_len++;
		max_index = max_index >> 1;
	}
	if (add_index(stack_1, len_stack) == -1)
		return (-1);
	lsb_radix(stack_1, stack_2, bit_len, len_stack);
	return (0);
}
