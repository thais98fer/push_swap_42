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

void	sort_three(t_stack *a)
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

int	is_sorted(int *pile_a, int size)
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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	stack_a.size = argc - 1;
	stack_a.stack = check_args(argv, stack_a.size);
	if (is_sorted(stack_a.stack, stack_a.size))
	{
		ft_printf("Pile A: ");
		while (i < stack_a.size)
		{
			ft_printf("%d\n", stack_a.stack[i]);
			i++;
		}
	}
	else if (stack_a.size == 3)
	{
		sort_three(&stack_a);
		ft_printf("Pile A: ");
		while (i < stack_a.size)
		{
			ft_printf("%d\n", stack_a.stack[i]);
			i++;
		}		
	}
	free(stack_a.stack);
	return (0);
}
