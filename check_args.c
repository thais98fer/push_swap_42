/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thais.fer <thais.fer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:55:14 by thais.fer         #+#    #+#             */
/*   Updated: 2025/11/25 11:55:17 by thais.fer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	*ft_error(char **argv, int size)
{
	int	*stack_a;

	if (!check_argv(argv))
	{
		ft_printf("Error\n");
		return (NULL);
	}
	stack_a = convert_args(argv, size);
	if (size > 1 && double_arg(stack_a) == 0)
	{
		ft_printf("Error\n");
		free(stack_a);
		return (NULL);
	}
	return (stack_a);
}

int	double_arg(int *stack_a)
{
	int	i;
	int	check;

	i = 0;
	while (stack_a[i])
	{
		check = i + 1;
		while (stack_a[check] == stack_a[i])
			return (0);
		check++;
	}
	i++;
	return (1);
}

int	*convert_args(char **argv, int size)
{
	int	*stack_a;
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack_a = (int *)malloc(size * (sizeof(int)));
	if (!stack_a)
		return (NULL);
	while (size != 0)
	{
		stack_a[i] = ft_atol(argv[j]);
		i++;
		j++;
		size--;
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
