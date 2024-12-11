/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xtoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:25:00 by grebrune          #+#    #+#             */
/*   Updated: 2024/12/11 21:48:07 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	xtoi_all(void *mlx, t_vars *vars, int width, int height)
{
	vars->img.skull_0 = mlx_xpm_file_to_image(mlx, \
	"img/skull/skull_0.xpm", &width, &height);
	vars->img.skull_1 = mlx_xpm_file_to_image(mlx, \
	"img/skull/skull_1.xpm", &width, &height);
	vars->img.skull_2 = mlx_xpm_file_to_image(mlx, \
	"img/skull/skull_2.xpm", &width, &height);
	vars->img.skull_3 = mlx_xpm_file_to_image(mlx, \
	"img/skull/skull_3.xpm", &width, &height);
	vars->img.skull_4 = mlx_xpm_file_to_image(mlx, \
	"img/skull/skull_4.xpm", &width, &height);
	vars->img.skull_5 = mlx_xpm_file_to_image(mlx, \
	"img/skull/skull_5.xpm", &width, &height);
	vars->img.skull_6 = mlx_xpm_file_to_image(mlx, \
	"img/skull/skull_6.xpm", &width, &height);
	vars->img.skull_7 = mlx_xpm_file_to_image(mlx, \
	"img/skull/skull_7.xpm", &width, &height);
}

void	xtoi_skull(void *mlx, t_vars *vars, int *width, int *height)
{
	vars->img.empty = mlx_xpm_file_to_image(mlx, \
	"img/empty.xpm", width, height);
	vars->img.monster_1 = mlx_xpm_file_to_image(mlx, \
	"img/opps_1.xpm", width, height);
	vars->img.monster_2 = mlx_xpm_file_to_image(mlx, \
	"img/opps_2.xpm", width, height);
	vars->img.monster_3 = mlx_xpm_file_to_image(mlx, \
	"img/opps_3.xpm", width, height);
	vars->img.wall = mlx_xpm_file_to_image(mlx, \
	"img/wall.xpm", width, height);
	vars->img.player_0 = mlx_xpm_file_to_image(mlx, \
	"img/frame_0.xpm", width, height);
	vars->img.player_1 = mlx_xpm_file_to_image(mlx, \
	"img/frame_1.xpm", width, height);
	vars->img.player_2 = mlx_xpm_file_to_image(mlx, \
	"img/frame_2.xpm", width, height);
	vars->img.door = mlx_xpm_file_to_image(mlx, \
	"img/door.xpm", width, height);
	vars->img.score = mlx_xpm_file_to_image(mlx, \
	"img/score.xpm", width, height);
	vars->img.exit = mlx_xpm_file_to_image(mlx, \
	"img/exit.xpm", width, height);
}

void	xpm_to_img(void *mlx, t_vars *vars)
{
	int		width;
	int		height;

	xtoi_skull(mlx, vars, &width, &height);
	xtoi_all(mlx, vars, width, height);
	if (!vars->img.empty || !vars->img.monster_1 \
		|| !vars->img.monster_2 || !vars->img.monster_3 \
		|| !vars->img.wall || !vars->img.skull_0 \
		|| !vars->img.skull_1 || !vars->img.skull_2 \
		|| !vars->img.skull_3 || !vars->img.skull_4 \
		|| !vars->img.skull_5 || !vars->img.skull_6 \
		|| !vars->img.skull_7 || !vars->img.player_0 \
		|| !vars->img.player_1 || !vars->img.player_2 \
		|| !vars->img.door || !vars->img.score || !vars->img.exit)
		close_win(vars);
}
