/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 21:13:27 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/18 09:31:25 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include <stdlib.h>

enum	e_limits
{
	int_min = -2147483648,
	int_max = 2147483647
};

typedef struct s_stack
{
	int	*stack;
	int	size;
}		t_stack;

typedef struct s_cost
{
	int	index_a;
	int	index_b;
	int	moves_a;
	int	moves_b;
	int	total;
}		t_cost;

int		main(int argc, char **argv);
int		ft_exec_instruction(char *line, t_stack *a, t_stack *b);
void	ft_read_and_exec(t_stack *a, t_stack *b);
void	ft_error(void);
void	ft_free(t_stack *pile);
int		ft_is_sorted(int *pile_a, int size);
int		ft_count_args(char **argv);
int		*check_args(char **argv, int *size);
void	process_arg(char *arg, int *stack, int *stack_i);
int		safe_limits(char *str);
int		is_number(char *str);
int		double_arg(int	*stack_a, int size);

// Push functions.
void	push(t_stack *src, t_stack *dest);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// Swap functions.
void	swap(t_stack *pile);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// Rotate functions.
void	rotate(t_stack *pile);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// Reverse rotate functions.
void	reverse_rotate(t_stack *pile);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
