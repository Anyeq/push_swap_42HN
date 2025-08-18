/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:14:57 by asando            #+#    #+#             */
/*   Updated: 2025/08/18 16:01:11 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_1, t_stack **stack_2)
{

	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_1;
	t_stack	*stack_2;
	t_stack	*curr;

	stack_1 = NULL;
	stack_2 = NULL;
	if (grab_arg(argc, argv, &stack_1) == 0)
	{
		push_swap(&stack_1, &stack_2);
		//curr = stack_1;
		//while (curr)
		//{
		//	ft_printf("%d\n", curr->value);
		//	curr = curr->next;
		//}
	}
		//do a push swap algorithm
	if (stack_1) //maybe we can clean two stack in one function
		stack_clean(&stack_1);
	// Error will lounch error massage in fd 2 STDERR
	return (0);
}
