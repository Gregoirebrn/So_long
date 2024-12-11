/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:40:03 by grebrune          #+#    #+#             */
/*   Updated: 2024/02/01 19:48:14 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player(t_vars *vars, t_img img, float time)
{
	if (time <= 300)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.player_0, img.i, img.x);
	else if (time <= 600)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.player_1, img.i, img.x);
	else if (time <= 900)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.player_2, img.i, img.x);
	else
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.player_1, img.i, img.x);
}

void	find_skull(t_vars *vars, t_img img, float time)
{
	if (time <= 150)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.skull_0, img.i, img.x);
	else if (time <= 300)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.skull_1, img.i, img.x);
	else if (time <= 450)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.skull_2, img.i, img.x);
	else if (time <= 600)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.skull_3, img.i, img.x);
	else if (time <= 750)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.skull_4, img.i, img.x);
	else if (time <= 900)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.skull_5, img.i, img.x);
	else if (time <= 1050)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.skull_6, img.i, img.x);
	else
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.skull_7, img.i, img.x);
}

void	find_monster(t_vars *vars, t_img img, float time)
{
	if (time <= 300)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.monster_1, img.i, img.x);
	else if (time <= 600)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.monster_2, img.i, img.x);
	else if (time <= 900)
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.monster_3, img.i, img.x);
	else
		mlx_put_image_to_window(vars->mlx, \
		vars->win, img.monster_2, img.i, img.x);
}

void	find_other(t_vars *vars, t_img img, char c)
{
	if (c == 'S')
		mlx_put_image_to_window(vars->mlx, \
			vars->win, img.score, 0, 0);
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, \
			vars->win, img.empty, img.i, img.x);
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, \
			vars->win, img.wall, img.i, img.x);
	if (c == 'E')
		mlx_put_image_to_window(vars->mlx, \
			vars->win, img.door, img.i, img.x);
	if (c == 'F')
		mlx_put_image_to_window(vars->mlx, \
			vars->win, img.exit, img.i, img.x);
}

void	find_img(t_vars *vars, t_img img, char c)
{
	float	time;

	gettimeofday(&vars->end, NULL);
	time = (vars->end.tv_sec - vars->start.tv_sec) \
	* 1000.0f + (vars->end.tv_usec - vars->start.tv_usec) / 1000.0f;
	if (time > 1050)
		gettimeofday(&vars->start, NULL);
	if (c == 'P')
		find_player(vars, img, time);
	if (c == 'M')
		find_monster(vars, img, time);
	if (c == 'C')
		find_skull(vars, img, time);
	find_other(vars, img, c);
}
