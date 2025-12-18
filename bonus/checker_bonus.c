/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:17:13 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/18 09:26:28 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_init_stack(t_stack *a, t_stack *b, int argc, char **argv)
{
	a->size = ft_count_args(argc, argv);
	a->stack = check_args(argv, a->size);
	if (!a->stack)
		ft_error();
	b->size = 0;
	b->stack = malloc(sizeof(int) * a->size);
	if (!b->stack)
		ft_error();
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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	ft_init_stacks(&a, &b, argc, argv);
	ft_read_and_exec(&a, &b);
	if (is_sorted(&a) && b.size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
	return (0);
}
