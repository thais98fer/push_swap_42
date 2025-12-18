/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:03:23 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/05 17:28:49 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack *src, t_stack *dest)
{
	int	i;

	i = dest->size;
	if (src->size == 0)
		return ;
	while (i > 0)
	{
		dest->stack[i] = dest->stack[i - 1];
		i--;
	}
	dest->stack[0] = src->stack[0];
	dest->size++;
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
