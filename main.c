/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:17:45 by thfernan          #+#    #+#             */
/*   Updated: 2025/11/26 18:37:35 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int	i;

	if (argc < 2)
		return (0);
	i = 0;
	stack_a.size = argc - 1;
	stack_a.stack = ft_error(argv, stack_a.size);
	stack_b.stack = malloc(sizeof(int) * stack_a.size);
	if (!stack_b.stack)
		return (ft_printf("Error\n"));
	stack_b.size = 0;
	while (i < stack_a.size)
	{
		ft_printf("Pile A:%d\n", stack_a.stack[i]);
		//ft_printf("Pile B:%d\n", stack_b.stack[i]);
		i++;
	}
	free(stack_a.stack);
	free(stack_b.stack);
	return (0);
}
