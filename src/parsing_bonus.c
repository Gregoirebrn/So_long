/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:32:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/24 16:38:18 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_border(char **tab)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = ft_strlen(tab[0]);
	while (tab[y])
	{
		if (tab[y][0] != '1' || tab[y][x - 1] != '1')
			return (ft_putstr_fd("Error\nThe map is incomplete.\n", 1), 1);
		y++;
	}
	x = 0;
	while (tab[0][x])
	{
		if (tab[0][x] != '1' || tab[y - 1][x] != '1')
			return (ft_putstr_fd("Error\n The map is incomplete.\n", 1), 1);
		x++;
	}
	return (0);
}

int	check_val(char **tab, t_val *val)
{
	size_t	y;
	size_t	x;

	set_to_zero(val);
	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			check_val_utils(tab, val, x, y);
			y++;
		}
		x++;
	}
	val->wy = (int)y;
	val->wx = (int)x;
	if (val->p_val != 1 || val->e_val != 1 || val->c_val < 1)
		return (ft_putstr_fd("Error\nMissing item in the map.\n", 1), 1);
	return (0);
}

void	find_path(char **tab, size_t x, size_t y)
{
	if (tab[x][y] != '1' && tab[x][y] != 'A' && tab[x][y] != 'M')
	{
		tab[x][y] = 'A';
		find_path(tab, x - 1, y);
		find_path(tab, x + 1, y);
		find_path(tab, x, y - 1);
		find_path(tab, x, y + 1);
	}
}

void	find_place(char **tmp, t_vars *vars, size_t y, size_t x)
{
	if (vars->map[x][y] == 'P')
	{
		vars->x = x;
		vars->y = y;
		find_path(tmp, x, y);
	}
}

int	check_path(char **tab, t_vars *vars)
{
	size_t	y;
	size_t	x;
	char	**tmp;

	x = 0;
	tmp = tab_dup(tab);
	while (tab[x])
	{
		y = 0;
		while (tab[x][y])
		{
			if (tab[x][y] != '0' && tab[x][y] != '1' && tab[x][y] != 'M' && \
			tab[x][y] != 'C' && tab[x][y] != 'E' && tab[x][y] != 'P')
				return (ft_putstr_fd("Error\nWrong item in the map.\n", 1), 1);
			find_place(tmp, vars, y, x);
			y++;
		}
		x++;
	}
	return (vars->bonus = true, still_c(tmp));
}
