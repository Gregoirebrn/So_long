/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:25:00 by grebrune          #+#    #+#             */
/*   Updated: 2024/02/01 21:48:07 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	finder(t_vars *vars)
{
	int		i;
	int		x;

	i = 2;
	x = 0;
	while (vars->map[x])
	{
		while (vars->map[x][i])
		{
			find_img(vars, vars->img, vars->map[x][i]);
			i++;
			vars->img.i += 60;
		}
		x++;
		vars->img.x += 60;
		i = 0;
		vars->img.i = 0;
	}
}

int	put_sprite(t_vars *vars)
{
	char	*str;

	xpm_to_img(vars->mlx, vars);
	vars->img.x = 0;
	vars->img.i = 120;
	finder(vars);
	find_img(vars, vars->img, 'S');
	mlx_string_put(vars->mlx, vars->win, 40, 15, 0xffff00, "MOVES ");
	str = ft_itoa(vars->move);
	if (!str)
	{
		ft_putstr_fd("Error\nMalloc crash, abort program", 1);
		close_win(vars);
	}
	mlx_string_put(vars->mlx, vars->win, 80, 15, 0xffff00, str);
	free(str);
	close_img(vars);
	return (1);
}
