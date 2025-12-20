/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thfernan <thfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:09:14 by thfernan          #+#    #+#             */
/*   Updated: 2025/12/20 16:41:46 by thfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_count_args(char **argv)
{
	char	**split;
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split)
		{
			ft_free_split(split);
			ft_error();
		}
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		ft_free_split(split);
		i++;
	}
	return (count);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
