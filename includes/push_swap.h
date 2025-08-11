/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:13:16 by asando            #+#    #+#             */
/*   Updated: 2025/08/11 12:58:12 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack 
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//main function
void	grab_arg(char *arg);

//stack utils function
t_stack	*stack_new(int content);
void	stack_add_back(int content, t_stack **stack);
void	stack_add_front(int content, t_stack **stack);

#endif
