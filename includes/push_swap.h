/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:13:16 by asando            #+#    #+#             */
/*   Updated: 2025/08/18 19:06:02 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef enum e_swap_flag
{
	SA = 1 << 0,
	SB = 1 << 1,
	SS = 1 << 2
}	t_swap_flag;

typedef enum e_push_flag
{
	PA = 1 << 0,
	PB = 1 << 1
}	t_push_flag;

//main function
int		grab_arg(int n_arg, char **s, t_stack **stack);

//stack utils function
t_stack	*stack_new(int content);
void	stack_add_front(int content, t_stack **stack);
void	stack_clean(t_stack **stack);
int		stack_add_back(int content, t_stack **stack);

#endif
