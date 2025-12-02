/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:03:23 by thfernan          #+#    #+#             */
/*   Updated: 2025/11/27 17:39:48 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	push(t_stack *src, t_stack *dst)
{
	int	i;

	i = src->size;
	if (src->size == 0)
		return ;
	while (i > 0)
	{
		dst->stack[i] = dst->stack[i - 1];
		i--;
	}
	dst->stack[0] = src->stack[0];
	dst->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->stack[i] = src->stack[i + 1];
		i++;
	}
	src->size--;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pb\n");
}
