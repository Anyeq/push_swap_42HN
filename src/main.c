/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:14:57 by asando            #+#    #+#             */
/*   Updated: 2025/09/15 15:30:12 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_1;
	t_stack	*stack_2;

	stack_1 = NULL;
	stack_2 = NULL;
	if (grab_arg(argc, argv, &stack_1) == 0)
	{
		if (turk_algo(&stack_1, &stack_2) == -1)
			write(2, "Error!, Stack not sorted\n", 25);
	}
	else
		write(2, "Error\n", 6);
	if (stack_1)
		stack_clean(&stack_1);
	return (0);
}
