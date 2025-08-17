/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asando <asando@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:37:10 by asando            #+#    #+#             */
/*   Updated: 2025/08/17 20:58:40 by asando           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	inside_range(char *s)
{
	long long	res;
	long long	sign;

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
		return (0);
	return (-1);
}

static int	is_valid(char *s, char **tmp)
{
	*tmp = *tmp;
	if (*s == '-' || *s == '+')
		s++;
	while (*s && *s != ' ' && *s != '\t')
	{
		if (*s < '0' || *s > '9')
			return (-1);
		s++;
	}
	if (*(s - 1) >= '0' && *(s - 1) <= '9')
	{
		*tmp = s;
		return (0);
	}
	return (-1);
}

static char	*first_content(char *s)
{
	while (*s && (*s == ' ' || *s == '\t'))
		s++;
	if (*s)
		return (s);
	return (NULL);
}

static int	parse_str_format(char *s, t_stack **stack)
{
	char	*res;
	char	*curr;

	res = NULL;
	curr = s;
	while (*curr)
	{
		res = first_content(curr);
		if (res && is_valid(res, &curr) == 0 && inside_range(res) == 0)
		{
			if (*stack == NULL)
			{
				*stack = stack_new(ft_atoi(res));
				if (*stack == NULL)
					return (-1);
			}
			else if (stack_add_back(ft_atoi(res), stack) < 0)
				return (-1);
		}
		else
			return (-1);
	}
	return (0);
}

int	grab_arg(int n_arg, char **s, t_stack **stack)
{
	int	i;

	i = 1;
	while (i < n_arg)
	{
		if (parse_str_format(s[i], stack) < 0)
			return (-1);
		i++;
	}
	return (0);
}
