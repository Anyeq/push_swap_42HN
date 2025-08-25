/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:14:57 by asando            #+#    #+#             */
/*   Updated: 2025/08/26 00:31:58 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr && curr->next != *stack)
	{
		ft_printf("%d --> index : %d\n", curr->value, curr->index);
		curr = curr->next;
	}
	if (*stack)
		ft_printf("%d --> index : %d\n", curr->value, curr->index);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_1;
	t_stack	*stack_2;

	stack_1 = NULL;
	stack_2 = NULL;
	if (grab_arg(argc, argv, &stack_1) == 0)
	{
		if (radix(&stack_1, &stack_2) == -1)
			write(2, "Error in processing the stack!\n", 31);
		//push_swap(&stack_1, &stack_2);
		//print_stack(&stack_1, &stack_2);	
		//swap_ps(&stack_1, &stack_2, SS);
		//push(&stack_1, &stack_2, PB);
		//push(&stack_1, &stack_2, PB);
		//swap(&stack_1, &stack_2, SS);
		//rotate(&stack_1, &stack_2, RR);
		print_stack(&stack_1);	
	}
	else
		write(2, "Error!\n", 7);
	if (stack_1)
		stack_clean(&stack_1);
	// Error will lounch error massage in fd 2 STDERR
	return (0);
}
