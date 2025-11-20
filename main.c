/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:17:45 by thfernan          #+#    #+#             */
/*   Updated: 2025/11/20 19:34:25 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	<limits.h>

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

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		str++;
	}
	return (result * sign);
}

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		i++;
	}
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

int	double_arg(int *stack_a)
{
	int	i;
	int	check;

	i = 0;
	while (stack_a[i])
	{
		check = i + 1;
		while (stack_a[check])
		{
			if (stack_a[check] == stack_a[i])
				return (0);
			check++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	size;
	int	i;

	stack_a = NULL;
	size = argc - 1;
	i = 0;
	if (argc > 1)
	{
		if (!check_args(argv))
		{
			ft_printf("Error\n");
			return (1);
		}
		stack_a = convert_args(argv, size);
		if (!stack_a)
			return (1);
		if (size > 1 && double_arg(stack_a) == 0)
		{
			ft_printf("Error\n");
			return (1);
		}	
		while (i < size)
		{
			ft_printf("%d\n", stack_a[i]);
			i++;
		}
	}
	free(stack_a);
	return (0);
}
