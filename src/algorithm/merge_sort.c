/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:09:43 by asando            #+#    #+#             */
/*   Updated: 2025/08/25 17:28:05 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"

static void	copy_arr(t_merge *mg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (mg->mid - mg->left + 1))
	{
		mg->left_arr[i] = mg->arr[mg->left + i];
		i++;
	}
	while (j < (mg->right - mg->mid))
	{
		mg->right_arr[j] = mg->arr[mg->mid + 1 + j];
		j++;
	}
}

static void	merge_arr(t_merge *mg)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < (mg->mid - mg->left + 1) && j < (mg->right - mg->mid))
	{
		if (mg->left_arr[i] < mg->right_arr[j])
			mg->arr[mg->left + k++] = mg->left_arr[i++];
		else
			mg->arr[mg->left + k++] = mg->right_arr[j++];
	}
	while (i < (mg->mid - mg->left + 1))
		mg->arr[mg->left + k++] = mg->left_arr[i++];
	while (j < (mg->right - mg->mid))
		mg->arr[mg->left + k++] = mg->right_arr[j++];
}

static int	merge_sorted_arr(int *arr, int left, int mid, int right)
{
	t_merge	mg;

	mg.left = left;
	mg.right = right;
	mg.mid = mid;
	mg.arr = arr;
	mg.left_arr = malloc(sizeof(int) * (mg.mid - mg.left + 1));
	mg.right_arr = malloc(sizeof(int) * (mg.right - mg.mid));
	if (mg.left_arr == NULL || mg.right_arr == NULL)
	{
		free(mg.left_arr);
		free(mg.right_arr);
		return (-1);
	}
	copy_arr(&mg);
	merge_arr(&mg);
	free(mg.left_arr);
	free(mg.right_arr);
	return (0);
}

int	merge_sort(int *arr, int left, int right)
{
	int	mid;

	mid = (right + left) / 2;
	if (left < right)
	{
		if (merge_sort(arr, left, mid) == -1)
			return (-1);
		if (merge_sort(arr, mid + 1, right) == -1)
			return (-1);
		if (merge_sorted_arr(arr, left, mid, right) == -1)
			return (-1);
	}
	return (0);
}
