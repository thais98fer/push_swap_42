/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:48:53 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/05 17:48:32 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_rotations(t_stack *a, t_stack *b, t_cost cost)
{
	while (cost.moves_a > 0 && cost.moves_b > 0)
	{
		rr(a, b);
		cost.moves_a--;
		cost.moves_b--;
	}
	while (cost.moves_a < 0 && cost.moves_b < 0)
	{
		rrr(a, b);
		cost.moves_a++;
		cost.moves_b++;
	}
	while (cost.moves_a > 0)
	{
		ra(a);
		cost.moves_a--;
	}
	while (cost.moves_a < 0)
	{
		rra(a);
		cost.moves_a++;
	}
	while (cost.moves_b > 0)
	{
		rb(b);
		cost.moves_b--;
	}
	while (cost.moves_b < 0)
	{
		rrb(b);
		cost.moves_b++;
	}
}

void	ft_move(t_stack *a, t_stack *b)
{
	t_cost	best;

	best = ft_best_move(a, b);
	ft_exec_rotations(a, b, best);
	pa (a, b);
}

void	ft_finalize(t_stack *a)
{
	int	i;
	int	min;
	int	min_index;
	int	moves;

	i = 0;
	min = ft_stack_min(a);
	min_index = 0;
	while (i < a->size)
	{
		if (a->stack[i] == min)
			min_index = i;
		i++;
	}
	moves = ft_moves_to_top(a, min_index);
	while (moves > 0)
	{
		ra(a);
		moves--;
	}
	while (moves < 0)
	{
		rra(a);
		moves++;
	}
}
