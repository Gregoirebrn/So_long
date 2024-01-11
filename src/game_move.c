/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:04:31 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/11 17:31:27 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_move(int keycode, t_vars *vars, t_val *val)
{
	if (keycode == 'w')
		map_move(vars, 0, -1, val);
	if (keycode == 'a')
		map_move(vars, -1, 0, val);
	if (keycode == 'd')
		map_move(vars, +1, 0, val);
	if (keycode == 's')
		map_move(vars, 0, 1, val);
	put_sprite(*vars);
}

void	map_move(t_vars *vars, int y, int x, t_val *val)
{
	int z;

	z = 0;
	printf("++++++++++%zu++++++++++++", val->c_val);
	if (vars->map[vars->x + x][vars->y + y] == 'C')
		val->c_val -= val->c_val - 1;
	if (val->c_val == 48){
		vars->map[vars->x_e][vars->y_e] = 'F';
	}
	if (vars->map[vars->x + x][vars->y + y] != '1')
	{
		vars->move += 1;
		vars->map[vars->x][vars->y] = '0';
		vars->map[vars->x + x][vars->y + y] = 'P';
		vars->x += x;
		vars->y += y;
	}
	if (vars->map[vars->x][vars->y] != vars->map[vars->x_e][vars->y_e])
		vars->map[vars->x_e][vars->y_e] = 'E';
	while (vars->map[z])
	{
		printf("%s\n", vars->map[z]);
		z++;
	}
	printf("\n");
}
