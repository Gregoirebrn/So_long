/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:04:31 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/09 18:13:26 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(int keycode, t_vars vars)
{
	if (keycode == 'W')
		map_move(vars, 0 , 1);
	if (keycode == 'A')
		map_move(vars, -1, 0);
	if (keycode == 'D')
		map_move(vars, +1, 0);
	if (keycode == 'S')
		map_move(vars, 0, -1);
	put_sprite(vars.mlx, vars.win, vars.map);
}

void	map_move(t_vars vars, int a, int o)
{
	static size_t count;

	if (vars.map[vars.x + a][vars.y + o] != 1)
	{
		if (vars.map[vars.x + a][vars.y + o] == 'C')
			count++;
		vars.map[vars.x][vars.y] = '0';
		vars.map[vars.x + a][vars.y + o] = 'P';
	}
}
