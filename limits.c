/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:17:49 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/20 13:54:14 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	safe_limits(char *str, int *out)
{
	long long	tmp;

	if (!is_number(str))
		return (0);
	tmp = ft_atol(str);
	if (tmp > int_max || tmp < int_min)
		return (0);
	*out = (int)tmp;
	return (1);
}

int	is_number(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
