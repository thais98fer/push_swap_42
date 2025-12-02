/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:17:45 by thfernan          #+#    #+#             */
/*   Updated: 2025/11/27 17:38:22 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

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
		&& a->stack[0] < a->stack[2])
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
}

//int	ft_push_swap()

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	a.size = argc - 1;
	b.size = argc - 1;
	a.stack = check_args(argv, a.size);
	b.stack = (int *)malloc(b.size * (sizeof(int)));
	ft_turk_sort(&a, &b);
	if (a.size > 1)
	{
		ft_printf("Pile A | Pile B\n");
		while (i < a.size)
		{
			ft_printf("%d        %d\n", a.stack[i], b.stack[i]);
			i++;
		}
	}
	free(a.stack);
	free(b.stack);
	return (0);
}
