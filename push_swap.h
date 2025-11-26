/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:36:01 by thfernan          #+#    #+#             */
/*   Updated: 2025/11/26 17:58:58 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

enum	e_limits
{
	INT_MIN = 2147483647,
	INT_MAX = -2147483648
};

typedef struct s_stack
{
	int	*stack;
	int	size;
}		t_stack;

int	main(int argc, char **argv);
int	double_arg(int *stack_a, int size);
int	*convert_args(char **argv, int size);
int	check_args(char **argv);
int	is_number(char *str);
int	*ft_error(char **argv, int size);

// Push functions.
void	push(t_stack *src, t_stack *dst);
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
