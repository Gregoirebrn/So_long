/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:04:31 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/09 20:02:04 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_move(int keycode, t_vars *vars)
{
	if (keycode == 'w')
		map_move(vars, 0 , -1);
	if (keycode == 'a')
		map_move(vars, -1, 0);
	if (keycode == 'd')
		map_move(vars, +1, 0);
	if (keycode == 's')
		map_move(vars, 0, 1);
	put_sprite(vars->mlx, vars->win, vars->map);
}

void	map_move(t_vars *vars, int y, int x)
{
	static size_t count;

	if (vars->map[vars->x + x][vars->y + y] != '1')
	{
		count++;
		vars->map[vars->x][vars->y] = '0';
		vars->map[vars->x + x][vars->y + y] = 'P';
		vars->x += x;
		vars->y += y;
	}
}
//		if (vars.map[vars.x + a][vars.y + o] == 'C')
