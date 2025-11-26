/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thais.fer <thais.fer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:55:14 by thais.fer         #+#    #+#             */
/*   Updated: 2025/11/26 18:31:22 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	*ft_error(char **argv, int size)
{
	int	*stack_a;

	if (!check_args(argv))
	{
		ft_printf("Error\n");
		return (NULL);
	}
	stack_a = convert_args(argv, size);
	if (size > 1 && double_arg(stack_a, size) == 0)
	{
		ft_printf("Error\n");
		free(stack_a);
		return (NULL);
	}
	return (stack_a);
}

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

int	*convert_args(char **argv, int size)
{
	int	*stack_a;
	int	i;

	i = 0;
	stack_a = (int *)malloc(size * (sizeof(int)));
	if (!stack_a)
		return (NULL);
	while (i < size)
	{
		stack_a[i] = ft_atol(argv[i + 1]);
		i++;
	}
	return (stack_a);
}

int	is_number(char *str)
{
	while (*str == '+' || *str == '-' || *str == ' ' || *str == '\t')
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

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if(!is_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
