/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:17:45 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/06 20:08:39 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *a)
{
	if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2]
		&& a->stack[0] < a->stack[2])
		sa(a);
	else if (a->stack[0] > a->stack[1] && a->stack[1] > a->stack[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2]
		&& a->stack[0] > a->stack[2])
		ra(a);
	else if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2]
		&& a->stack[0] < a->stack[2])
	{
		sa(a);
		ra(a);
	}
	else if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2]
		&& a->stack[0] > a->stack[2])
		rra(a);
}

int	ft_is_sorted(int *pile_a, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (pile_a[i] > pile_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_turk_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (ft_is_sorted(a->stack, a->size))
		return ;
	if (a->size == 2)
	{
		if (a->stack[0] > a->stack[1])
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		ft_sort_three(a);
		return ;
	}
	while (size > 3)
	{
		pb(a, b);
		size--;
	}
	ft_sort_three(a);
	while (b->size > 0)
		ft_move(a, b);
	ft_finalize(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = malloc(sizeof(t_stack));
	if (!a)
		return (1);
	a->size = argc - 1;
	a->stack = check_args(argv, a->size);
	b = ft_calloc(sizeof(t_stack), 1);
	b->stack = malloc(a->size * sizeof(int));
	if (!a->stack || !b->stack)
		return (1);
	ft_turk_sort(a, b);
	ft_free(a);
	ft_free(b);
	return (0);
}
