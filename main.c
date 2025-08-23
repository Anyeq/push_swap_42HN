/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:14:57 by asando            #+#    #+#             */
/*   Updated: 2025/08/23 16:50:01 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_stack **stack_1, t_stack **stack_2)
{
	int	arr_1[10] = {0};
	int	arr_2[10] = {0};
	t_stack	*curr;
	int	i = 0;

	curr = *stack_1;
	while (curr && curr->next != *stack_1)
	{
		arr_1[i] = curr->value;
		curr = curr->next;
		i++;
	}
	if (*stack_1)
		arr_1[i] = curr->value;
	curr = *stack_2;
	i = 0;
	while (curr && curr->next != *stack_2)
	{
		arr_2[i] = curr->value;
		curr = curr->next;
		i++;
	}
	if (*stack_2)
		arr_2[i] = curr->value;
	i = 0;
	while (i < 10)
	{
		ft_printf("%d	%d\n", arr_1[i], arr_2[i]);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_1;
	t_stack	*stack_2;
	//t_stack	*curr;

	stack_1 = NULL;
	stack_2 = NULL;
	if (grab_arg(argc, argv, &stack_1) == 0)
	{
		//push_swap(&stack_1, &stack_2);
		print_stack(&stack_1, &stack_2);	
		//swap_ps(&stack_1, &stack_2, SS);
		push(&stack_1, &stack_2, PB);
		push(&stack_1, &stack_2, PB);
		swap(&stack_1, &stack_2, SS);
		rotate(&stack_1, &stack_2, RR);
		print_stack(&stack_1, &stack_2);	
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
