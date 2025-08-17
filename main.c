/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:14:57 by asando            #+#    #+#             */
/*   Updated: 2025/08/17 21:04:02 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	//int	i;
	t_stack	*stack_1;
	t_stack	*curr;

	//i = 1;
	stack_1 = NULL;
	if (grab_arg(argc, argv, &stack_1) == 0)
	{
		curr = stack_1;
		while (curr)
		{
			ft_printf("%d\n", curr->value);
			curr = curr->next;
		}
	}
		//do a push swap algorithm
	if (stack_1)
		stack_clean(&stack_1);
	//ft_printf("Error\n");
	return (0);
}
