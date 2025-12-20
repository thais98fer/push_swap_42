/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:59:41 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/20 17:17:21 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_stack *pile)
{
	int	i;
	int	last;

	if (pile->size < 2)
		return ;
	i = pile->size - 1;
	last = pile->stack[pile->size - 1];
	while (i > 0)
	{
		pile->stack[i] = pile->stack[i - 1];
		i--;
	}
	pile->stack[0] = last;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
