/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:58:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/11 19:18:04 by grebrune         ###   ########.fr       */
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
			return (ft_putstr_fd("Error : the map is incomplete.\n", 1), 1);
		y++;
	}
	x = 0;
	while (tab[0][x])
	{
		if (tab[0][x] != '1' || tab[y - 1][x] != '1')
			return (ft_putstr_fd("Error : the map is incomplete.\n", 1), 1);
		x++;
	}
	if (x == y)
		return (ft_putstr_fd("Error : Map is not a rectangle.\n", 1), 1);
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
			y++;
		}
		x++;
	}
	if (val->p_val != 1 || val->e_val != 1 || val->c_val < 1)
		return (ft_putstr_fd("Error : Missing item in the map.\n", 1), 1);
	return (0);
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
				return (ft_putstr_fd("Error : Issue with collectible.", 1), 1);
			if (tab[x][y] == 'E')
				return (ft_putstr_fd("Error : No valid path find.\n", 1), 1);
			y++;
		}
		x++;
	}
	return (ft_free(tab), 0);
}

void	find_path(char **tab, size_t x, size_t y)
{
	if (tab[x][y] != '1' && tab[x][y] != 'A')
	{
		tab[x][y] = 'A';
		find_path(tab, x - 1, y);
		find_path(tab, x + 1, y);
		find_path(tab, x, y - 1);
		find_path(tab, x, y + 1);
	}
}

void	find_place(char **tmp, char **tab, t_vars *vars, size_t y, size_t x)
{
	if (tab[x][y] == 'P')
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
		while (tab[y])
		{
			find_place(tmp, tab, vars, y, x);
			y++;
		}
		x++;
	}
	return (still_c(tmp));
}
