/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:36:01 by thfernan          #+#    #+#             */
/*   Updated: 2025/11/20 18:43:58 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>

int	main(int argc, char **argv);
int	double_arg(int *stack_a);
int	*convert_args(char **argv, int size);
int	check_args(char **argv);
int	is_number(char *str);
int	*ft_error(char **argv, int size);

#endif
