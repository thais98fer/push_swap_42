/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:03:26 by thfernan          #+#    #+#             */
/*   Updated: 2025/11/27 17:24:10 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	rotate(t_stack *pile)
{
	int	i;
	int	first;

	if (pile->size < 2)
		return ;
	first = pile->stack[0];
	i = 0;
	while (i < pile->size - 1)
	{
		pile->stack[i] = pile->stack[i + 1];
		i++;
	}
	pile->stack[pile->size -1] = first;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
