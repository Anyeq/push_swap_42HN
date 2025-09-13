/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:39:01 by asando            #+#    #+#             */
/*   Updated: 2025/09/13 23:49:07 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TURK_ALGORITHM_H
# define TURK_ALGORITHM_H

int		turk_algo(t_stack **stack_1, t_stack **stack_2);
t_stack	*max_value(t_stack **stack);
t_stack	*min_value(t_stack **stack);
void	last_move(t_stack **stack);
void	move_stack(t_stack **stack_1, t_stack **stack_2, t_op_flag flag);
void	init_stack(t_stack **stack_1, t_stack **stack_2, int direction);
void	set_middle_index(t_stack **stack);
int		check_sorted_list(t_stack **stack);
#endif
