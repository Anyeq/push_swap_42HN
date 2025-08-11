/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:37:10 by asando            #+#    #+#             */
/*   Updated: 2025/08/11 14:30:45 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	inside_range(const char *s)
{

}

static int	is_double(const char *s)
{

}

static int	is_valid(const char *s, char *tmp)
{
	if (*s == '-' || *s == '+')
		s++;
	while (*s && *s != ' ' && *s != '\t')
	{ 
		if (*s < '0' && *s > '9')
			return (0);
		s++;
	}
	if (*(s - 1) >= '0' && *(s - 1) <= '9')
	{
		tmp = s;
		return (1);
	}
	return (0);
}

static char	*first_content(const char *s)
{
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (*s)
		return (s);
	return (NULL);
}

static int	parse_str_format(const char *s, t_stack **stack)
{
	char *res;
	char *curr;
	int	num;

	res = NULL;
	curr = s;
	num = 0;
	while (curr)
	{
		res = first_content(curr);
		if (res && is_valid(res, curr))
		{
			num = ft_atoi(res);
			if (*stack == NULL)
				*stack = stack_new(ft_atoi(s[i]));
			else
				stack_add_back(ft_atoi(s[i]), *stack);
		}
		else
				return (0);
	}
	return (1);
}

int	grab_arg(int n_arg, char **s, t_stack **stack)
{
	int	i;

	i = 1;
	while (i < n_arg)
	{
		if (is_valid(s[i]))
		{
			if (*stack == NULL)
				*stack = stack_new(ft_atoi(s[i]));
			else
				stack_add_back(ft_atoi(s[i]), *stack);
			i++;
		}
		else
			return (0);
	}
	return (1);
}
