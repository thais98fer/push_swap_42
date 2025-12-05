/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:04:31 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/05 18:09:43 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_moves_to_top(t_stack *pile, int index)
{
	if (index <= pile->size / 2)
		return (index);
	else
		return (index - pile->size);
}

t_cost	ft_calculate_cost(t_stack *a, t_stack *b, int index_b)
{
	t_cost	cost;
	int		b_nbr;

	b_nbr = b->stack[index_b];
	cost.index_b = index_b;
	cost.index_a = ft_find_target(a, b_nbr);
	cost.moves_a = ft_moves_to_top(a, cost.index_a);
	cost.moves_b = ft_moves_to_top(b, index_b);
	if (cost.moves_a >= 0 && cost.moves_b >= 0)
	{
		if (cost.moves_a > cost.moves_b)
			cost.total = cost.moves_a;
		else
			cost.total = cost.moves_b;
	}
	else if (cost.moves_a < 0 && cost.moves_b < 0)
	{
		if (-cost.moves_a > -cost.moves_b)
			cost.total = -cost.moves_a;
		else
			cost.total = -cost.moves_b;
	}
	else
		cost.total = ft_nbr_abs(cost.moves_a) + ft_nbr_abs(cost.moves_b);
	return (cost);
}

t_cost	ft_best_move(t_stack *a, t_stack *b)
{
	int		i;
	t_cost	best;
	t_cost	tmp;

	best.total = int_max;
	i = 0;
	while (i < b->size)
	{
		tmp = ft_calculate_cost(a, b, i);
		if (tmp.total < best.total)
			best = tmp;
		i++;
	}
	return (best);
}
