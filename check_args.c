/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:55:14 by thais.fer         #+#    #+#             */
/*   Updated: 2025/12/20 13:55:23 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	fill_array(char **split, int *stack, int *stack_i)
{
	int	i;
	int	value;

	i = 0;
	while (split[i])
	{
		if (!safe_limits(split[i], &value))
		{
			ft_free_split(split);
			return (0);
		}
		stack[*stack_i] = value;
		(*stack_i)++;
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	process_arg(char *arg, int *stack, int *stack_i)
{
	char	**split;

	if (!arg || arg[0] == '\0')
		return (0);
	split = ft_split(arg, ' ');
	if (!split || !split[0])
	{
		ft_free_split(split);
		return (0);
	}
	if (!fill_array(split, stack, stack_i))
		return (0);
	return (1);
}

int	check_args(char **argv, int *stack_a, int *size)
{
	int	arg_i;
	int	i;

	arg_i = 1;
	i = 0;
	while (argv[arg_i])
	{
		if (!process_arg(argv[arg_i], stack_a, &i))
			return (0);
		arg_i++;
	}
	if (!double_arg(stack_a, *size))
		return (0);
	return (1);
}

int	*receive_args(char **argv, int *size)
{
	int	*stack_a;

	*size = ft_count_args(argv);
	if (*size == 0)
		return (0);
	stack_a = (int *)malloc(*size * (sizeof(int)));
	if (!stack_a)
		return (NULL);
	if (!check_args(argv, stack_a, size))
	{
		free(stack_a);
		return (0);
	}
	return (stack_a);
}
