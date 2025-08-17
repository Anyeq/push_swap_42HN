/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:13:16 by asando            #+#    #+#             */
/*   Updated: 2025/08/17 18:21:04 by asando           ###   ########.fr       */
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

//main function
int	grab_arg(int n_arg, char **s, t_stack **stack);

//stack utils function
t_stack	*stack_new(int content);
int	stack_add_back(int content, t_stack **stack);
void	stack_add_front(int content, t_stack **stack);
void	stack_clean(t_stack **stack);
#endif
