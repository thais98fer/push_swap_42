/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:17:13 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/20 17:06:18 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	(void)argc;
	a->size = ft_count_args(argv);
	a->stack = receive_args(argv, &a->size);
	if (!a->stack)
	{
		ft_free(a);
		ft_error();
	}
	b->size = 0;
	b->stack = malloc(sizeof(int) * a->size);
	if (!b->stack)
	{
		ft_free(a);
		ft_error();
	}
}

void	ft_read_and_exec(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!ft_exec_instruction(line, a, b))
		{
			free(line);
			ft_error();
		}
		free(line);
		line = get_next_line(0);
	}
}

int	ft_exec_instruction(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b);
	else
		return (0);
	return (1);
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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	ft_init_stack(&a, &b, argc, argv);
	ft_read_and_exec(&a, &b);
	if (ft_is_sorted(a.stack, a.size) && b.size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free(&a);
	ft_free(&b);
	return (0);
}
