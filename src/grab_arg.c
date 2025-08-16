/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:37:10 by asando            #+#    #+#             */
/*   Updated: 2025/08/12 21:34:50 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	inside_range(const char *s)
{
	long long res;
	long long sign;

	sign = 0;
	res = 0;
	while (*s && (*s == '-' || *s == '+'))
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
	{
		res = res * 10 + ((*s - '0') * sign);
		s++;
	}
	if (res <= 2147483647 && res >= -2147483648)
		return (1);
	return (0);
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

	res = NULL;
	curr = s;
	while (curr)
	{
		res = first_content(curr);
		if (res && is_valid(res, curr) && inside_range(res))
		{
			if (*stack == NULL)
				*stack = stack_new(ft_atoi(res);
			else
			{
				if (!stack_add_back(ft_atoi(res), *stack))
					return (0);
			}
		}
		else
				return (0);
	}
	return (1);
}

//double, inside_range, malloc failed, is_valid
int	grab_arg(int n_arg, char **s, t_stack **stack)
{
	int	i;

	i = 1;
	while (i < n_arg)
	{
		if (parse_str_format(s[i], stack))
			return (0);
		i++;
	}
	return (1);
}
