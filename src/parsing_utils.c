/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:09:13 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/18 13:09:13 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_val_utils(char **tab, t_val *val, size_t x, size_t y)
{
	if (tab[x][y] == 'P')
		val->p_val++;
	else if (tab[x][y] == 'E')
	{
		val->e_val++;
		val->x = x;
		val->y = y;
	}
	else if (tab[x][y] == 'C')
		val->c_val++;
}

int	still_c(char **tab)
{
	size_t	y;
	size_t	x;

	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] == 'C')
				return (ft_putstr_fd("Error\nIssue with collectible.", 1), 1);
			if (tab[x][y] == 'E')
				return (ft_putstr_fd("Error\nNo valid path find.\n", 1), 1);
			y++;
		}
		x++;
	}
	return (ft_free(tab), 0);
}
