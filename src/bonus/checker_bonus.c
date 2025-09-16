/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:51:03 by asando            #+#    #+#             */
/*   Updated: 2025/09/16 22:00:45 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	check_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	if (stack == NULL || *stack == NULL)
		return (-1);
	while (current->next != *stack)
	{
		if (current->value > (current->next)->value)
			return (-1);
		current = current->next;
	}
	return (0);
}

static int	move_input(char *move, t_stack **stack_1, t_stack **stack_2)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		swap(stack_1, stack_2, SA, 1);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		swap(stack_1, stack_2, SB, 1);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		swap(stack_1, stack_2, SS, 1);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		push(stack_1, stack_2, PA, 1);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		push(stack_1, stack_2, PB, 1);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		rotate(stack_1, stack_2, RA, 1);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rotate(stack_1, stack_2, RB, 1);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rotate(stack_1, stack_2, RR, 1);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		reverse_rotate(stack_1, stack_2, RRA, 1);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		reverse_rotate(stack_1, stack_2, RRB, 1);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		reverse_rotate(stack_1, stack_2, RRR, 1);
	else
		return (-1);
	return (0);
}

static int	execute_move(t_stack **stack_1, t_stack **stack_2)
{
	char	*res;

	res = NULL;
	while (1)
	{
		res = get_next_line(STDIN_FILENO);
		if (res == NULL)
			return (0);
		if (move_input(res, stack_1, stack_2) == -1)
		{
			free(res);
			return (-1);
		}
		free(res);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_1;
	t_stack	*stack_2;

	stack_1 = NULL;
	stack_2 = NULL;
	if (argc == 1)
		return (0);
	if (grab_arg(argc, argv, &stack_1) == 0)
	{
		if (execute_move(&stack_1, &stack_2) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (check_sorted(&stack_1) == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	else
		write(2, "Error\n", 6);
	if (stack_1)
		stack_clean(&stack_1);
	if (stack_2)
		stack_clean(&stack_2);
	return (0);
}
