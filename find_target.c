/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:44:53 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/17 19:07:02 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_min(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = int_max;
	while (i < a->size)
	{
		if (a->stack[i] < min)
			min = a->stack[i];
		i++;
	}
	return (min);
}

int	ft_stack_max(t_stack *a)
{
	int	i;
	int	max;

	i = 0;
	max = int_min;
	while (i < a->size)
	{
		if (a->stack[i] > max)
			max = a->stack[i];
		i++;
	}
	return (max);
}

int	ft_find_smallest_bigger(t_stack *a, int b_nbr)
{
	int	i;
	int	target;
	int	smallest;

	i = 0;
	target = -1;
	smallest = int_max;
	while (i < a->size)
	{
		if (a->stack[i] > b_nbr && a->stack[i] < smallest)
		{
			smallest = a->stack[i];
			target = i;
		}
		i++;
	}
	return (target);
}

int	ft_find_min_index(t_stack *a)
{
	int	i;
	int	min;

	min = ft_stack_min(a);
	i = 0;
	while (i < a->size)
	{
		if (a->stack[i] == min)
			return (i);
		i++;
	}
	return (0);
}

int	ft_find_target(t_stack *a, int b_nbr)
{
	int	target;

	target = ft_find_smallest_bigger(a, b_nbr);
	if (target == -1)
		return (ft_find_min_index(a));
	return (target);
}
