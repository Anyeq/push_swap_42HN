/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:27:06 by asando            #+#    #+#             */
/*   Updated: 2025/08/24 20:50:16 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_SORT_H
# define MERGE_SORT_H

typedef struct	s_merge
{
	int	*arr;
	int	*left_arr;
	int	*right_arr;
	int	left;
	int	mid;
	int	right;
}	t_merge_sort;

#endif
