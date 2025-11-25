/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:17:45 by thfernan          #+#    #+#             */
/*   Updated: 2025/11/20 19:34:25 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"
#include	<limits.h>

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	size;
	int	i;

	stack_a = NULL;
	size = argc - 1;
	i = 0;
	if (argc > 1)
	{
		stack_a = ft_error(argv, size);
		while (i < size)
		{
			ft_printf("%d\n", stack_a[i]);
			i++;
		}
	}
	free(stack_a);
	return (0);
}
