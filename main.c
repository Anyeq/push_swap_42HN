/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:14:57 by asando            #+#    #+#             */
/*   Updated: 2025/08/11 13:34:53 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	i;
	t_stack	*stack_1;

	i = 1;
	stack_1 = NULL;
	if (grab_arg(argc, argv, &stack_1))
		//do a push swap algorithm
		;
	else
	{
		if (*stack)
			stack_clean(*stack);
		ft_printf("Error\n");
	}
	return (0);
}
