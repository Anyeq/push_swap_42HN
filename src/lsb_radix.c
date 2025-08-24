/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsb_radix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:59:59 by asando            #+#    #+#             */
/*   Updated: 2025/08/24 09:50:49 by asando           ###   ########.fr       */
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

static int	merge_arr(int *arr, int left, int mid, int right)
{
	int	i;
	int	j;
	int	k;
	int	*left_arr;
	int	*right_arr;

	i = 0;
	j = 0;
	k = 0;
	left_arr = malloc(sizeof(int) * (mid - left + 1));
	right_arr = malloc(sizeof(int) * (right - mid));
	if (left_arr == NULL || right_arr == NULL)
	{
		free(left_arr);
		free(right_arr);
		return (-1);
	}
	while (i < (mid - left + 1))
	{
		left_arr[i] = arr[left + i];
		i++;
	}
	while (j < (right- mid))
	{
		right_arr[j] = arr[mid + 1 + j];
		j++;
	}
	i = 0;
	j = 0;
	while (i < (mid - left + 1) && j < (right - mid))
	{
		if (left_arr[i] < right_arr[j])
			arr[left + k++] = left_arr[i++];
		else
			arr[left + k++] = right_arr[j++];
	}
	while (i < (mid - left + 1))
		arr[left + k++] = left_arr[i++];
	while (j < (right - mid))
		arr[left + k++] = right_arr[j++];
	free(left_arr);
	free(right_arr);
	return (0);
}

static int	merge_sort(int *arr, int left, int right)
{
	int	mid;

	mid = (right - left) / 2;
	if (left < right)
	{
		if (merge_sort(arr, left, mid) == -1)
			return (-1);
		if (merge_sort(arr, mid + 1, right) == -1)
			return (-1);
		if (merged_arr(arr, left, mid, right) == -1)
			return (-1);
	}
	return (0);
}

int	lsb_radix(t_stack **stack_1, t_stack **stack_2)
{
	return (0);
}
