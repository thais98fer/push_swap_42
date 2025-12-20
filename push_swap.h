/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:36:01 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/20 13:54:29 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

// Main and verifications.
int		main(int argc, char **argv);
int		double_arg(int *stack_a, int size);
int		*receive_args(char **argv, int *size);
int		check_args(char **argv, int *stack_a, int *size);
int		is_number(char *str);
int		safe_limits(char *str, int *out);
int		process_arg(char *arg, int *stack, int *stack_i);
void	ft_error(void);
void	ft_free(t_stack *pile);
int		ft_count_args(char **argv);
void	ft_free_split(char **split);

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

// Finding target.
int		ft_stack_min(t_stack *a);
int		ft_stack_max(t_stack *a);
int		ft_find_smallest_bigger(t_stack *a, int b_nbr);
int		ft_find_min_index(t_stack *a);
int		ft_find_target(t_stack *a, int b_nbr);

// Calculating moves.
int		ft_moves_to_top(t_stack *pile, int index);
t_cost	ft_calcuate_cost(t_stack *a, t_stack *b, int index_b);
t_cost	ft_best_move(t_stack *a, t_stack *b);

// Moving.
void	ft_exec_double_rotations(t_stack *a, t_stack *b, t_cost *cost);
void	ft_exec_single_rotations(t_stack *s, int *moves, char stack);
void	ft_exec_rotations(t_stack *a, t_stack *b, t_cost cost);
void	ft_move(t_stack *a, t_stack *b);
void	ft_finalize(t_stack *a);

// Final algoritm.
int		ft_is_sorted(int *pile_a, int size);
void	ft_sort_three(t_stack *a);
void	ft_turk_sort(t_stack *a, t_stack *b);

#endif
