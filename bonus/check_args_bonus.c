/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:55:14 by thais.fer         #+#    #+#             */
/*   Updated: 2025/12/17 18:18:43 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	double_arg(int *stack_a, int size)
{
	int	i;
	int	check;

	i = 0;
	while (i < size)
	{
		check = i + 1;
		while (check < size)
		{
			if (stack_a[i] == stack_a[check])
				return (0);
			check++;
		}
		i++;
	}
	return (1);
}

int	is_number(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	safe_limits(char *str)
{
	long long	tmp;
	int			sign;

	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	if (*str == '\0')
		return (0);
	tmp = ft_atol(str) * sign;
	if (tmp > int_max || tmp < int_min)
		ft_error();
	return ((int)tmp);
}

void	process_arg(char *arg, int *stack, int *stack_i)
{
	char	**split;
	int		i;

	split = ft_split(arg, ' ');
	if (!split)
		ft_error();
	i = 0;
	while (split[i])
	{
		if (!is_number(split[i]))
			ft_error();
		stack[*stack_i] = safe_limits(split[i]);
		(*stack_i)++;
		i++;
	}
	ft_free_split(split);
}

int	*check_args(char **argv, int *size)
{
	int	*stack_a;
	int	arg_i;
	int	i;

	*size = ft_count_args(argv);
	if (*size == 0)
		ft_error();
	stack_a = (int *)malloc(*size * (sizeof(int)));
	if (!stack_a)
		return (NULL);
	arg_i = 1;
	i = 0;
	while (argv[arg_i])
	{
		process_arg(argv[arg_i], stack_a, &i);
		arg_i++;
	}
	if (!double_arg(stack_a, *size))
	{
		free(stack_a);
		ft_error();
	}
	return (stack_a);
}
