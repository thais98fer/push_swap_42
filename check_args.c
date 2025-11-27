/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thais.fer <thais.fer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:55:14 by thais.fer         #+#    #+#             */
/*   Updated: 2025/11/27 17:39:31 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

/*long long	int_limits(long long *stack_a, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack_a[i] > INT_MAX || stack_a[i] < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}*/

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

int	*check_args(char **argv, int size)
{
	int	*stack_a;
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			ft_error();
		i++;
	}
	stack_a = (int *)malloc(size * (sizeof(int)));
	if (!stack_a)
		return (NULL);
	i = 0;
	while (i < size)
	{
		stack_a[i] = ft_atol(argv[i + 1]);
		i++;
	}
	if (!double_arg(stack_a, size)) //|| !int_limits(stack_a, size))
		ft_error();
	return (stack_a);
}
