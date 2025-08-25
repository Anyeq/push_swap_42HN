/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:59:59 by asando            #+#    #+#             */
/*   Updated: 2025/08/26 00:28:28 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "merge_sort.h"

static int	*store_to_array(t_stack **stack, int len_stack)
{
	int		*arr_value;
	t_stack	*curr;
	int		i;

	i = 0;
	curr = *stack;
	arr_value = malloc(sizeof(int) * len_stack);
	if (arr_value == NULL)
		return (NULL);
	if (stack == NULL || *stack == NULL)
	{
		free(arr_value);
		return (NULL);
	}
	while (i < len_stack)
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

static int	add_index(t_stack **stack, int len)
{
	t_stack	*curr;
	int		*arr;
	int		idx;

	idx = 0;
	arr = store_to_array(stack, len);
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
			curr->index = binary_search(arr, len, curr->value);
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
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < bit_len)
	{
		j = 0;
		while (j < len_stack && *stack_1)
		{
			if (((*stack_1)->index & (1 << i)) == 0)
				push(stack_1, stack_2, PB);
			else
				rotate(stack_1, stack_2, RA);
			j++;
		}
		push_all(stack_1, stack_2, PA);
		i++;
	}
	return ;
}

int	radix(t_stack **stack_1, t_stack **stack_2)
{
	int		len_stack;
	int		bit_len;
	int		max_index;

	len_stack = stack_size(stack_1);
	bit_len = 0;
	max_index = len_stack;
	//only for test
	//if (*stack_2 != NULL)
	//	return (-1);
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
