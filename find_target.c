/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 10:44:53 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/05 17:58:59 by thfernan         ###   ########.fr       */
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

int	ft_find_target(t_stack *a, int b_nbr)
{
	int	i;
	int	target_index;
	int	smallest_bigger;
	int	min_value;

	i = 0;
	target_index = -1;
	smallest_bigger = int_max;
	min_value = ft_stack_min(a);
	while (i < a->size)
	{
		if (a->stack[i] > b_nbr && a->stack[i] < smallest_bigger)
		{
			smallest_bigger = a->stack[i];
			target_index = i;
		}
		i++;
	}
	if (target_index == -1)
	{
		i = 0;
		while (i < a->size)
		{
			if (a->stack[i] == min_value)
				return (i);
			i++;
		}
	}
	return (target_index);
}
