/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thais.fer <thais.fer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:36:01 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/02 09:29:38 by thais.fer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

enum	e_limits
{
	INT_MIN = -2147483648,
	INT_MAX = 2147483647
};

typedef struct s_stack
{
	int	*stack;
	int	size;
}		t_stack;

typedef struct s_num
{
	int	value;
	int	index;
}		t_num;

typedef struct	s_cost
{
	int	index_a;
	int	index_b;
	int	moves_a;
	int	moves_b;
	int	total;
}		t_cost;

int			main(int argc, char **argv);
int			double_arg(int *stack_a, int size);
int			*check_args(char **argv, int size);
int			is_number(char *str);
//long long	int_limits(long long *stack_a, int size);
void		ft_error(void);

// Push functions.
void		push(t_stack *src, t_stack *dst);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);

// Swap functions.
void		swap(t_stack *pile);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

// Rotate functions.
void		rotate(t_stack *pile);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);

// Reverse rotate functions.
void		reverse_rotate(t_stack *pile);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

// Algoritm.
int			ft_is_sorted(int *pile_a, int size);
void		ft_sort_three(t_stack *a);
void		ft_turk_sort(t_stack *a, t_stack *b);

#endif
