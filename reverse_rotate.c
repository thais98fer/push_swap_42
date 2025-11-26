/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:59:41 by thfernan          #+#    #+#             */
/*   Updated: 2025/11/26 17:32:45 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

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
	ft_printf("rra");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr");
}
