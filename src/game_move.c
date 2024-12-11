/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:04:31 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/24 16:08:50 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_move(t_vars *vars, int y, int x)
{
	if (vars->map[vars->x + x][vars->y + y] == 'M')
		return (write(1, "You Died :/\n", 12), close_win(vars), (void)0);
	if (vars->map[vars->x + x][vars->y + y] == 'C')
		vars->val->c_val--;
	if (vars->val->c_val == 0)
		vars->map[vars->val->x][vars->val->y] = 'F';
	if (vars->map[vars->x + x][vars->y + y] != '1')
	{
		vars->move += 1;
		if (!vars->bonus)
			ft_printf("%d moves\n", (int)vars->move);
		vars->map[vars->x][vars->y] = '0';
		if (vars->map[vars->x][vars->y] == vars->map[vars->val->x] \
		[vars->val->y] && vars->val->c_val == 0)
			vars->map[vars->x][vars->y] = 'F';
		else if (vars->map[vars->x][vars->y] == vars->map[vars->val->x] \
		[vars->val->y])
			vars->map[vars->x][vars->y] = 'E';
		vars->map[vars->x + x][vars->y + y] = 'P';
		vars->x += x;
		vars->y += y;
	}
}

void	player_move(int keycode, t_vars *vars)
{
	if (keycode == 'w')
		map_move(vars, 0, -1);
	if (keycode == 'a')
		map_move(vars, -1, 0);
	if (keycode == 'd')
		map_move(vars, +1, 0);
	if (keycode == 's')
		map_move(vars, 0, 1);
	put_sprite(vars);
}
