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

void	xpm_to_img(void *mlx, t_vars *vars)
{
	int		width;
	int		height;
	vars->img.skull_0 = mlx_xpm_file_to_image(mlx, "img/skull/skull_0.xpm", &width, &height);
	vars->img.skull_1 = mlx_xpm_file_to_image(mlx, "img/skull/skull_1.xpm", &width, &height);
	vars->img.skull_2 = mlx_xpm_file_to_image(mlx, "img/skull/skull_2.xpm", &width, &height);
	vars->img.skull_3 = mlx_xpm_file_to_image(mlx, "img/skull/skull_3.xpm", &width, &height);
	vars->img.skull_4 = mlx_xpm_file_to_image(mlx, "img/skull/skull_4.xpm", &width, &height);
	vars->img.skull_5 = mlx_xpm_file_to_image(mlx, "img/skull/skull_5.xpm", &width, &height);
	vars->img.skull_6 = mlx_xpm_file_to_image(mlx, "img/skull/skull_6.xpm", &width, &height);
	vars->img.skull_7 = mlx_xpm_file_to_image(mlx, "img/skull/skull_7.xpm", &width, &height);

	vars->img.empty = mlx_xpm_file_to_image(mlx, "img/empty.xpm", &width, &height);
	vars->img.monster_1 = mlx_xpm_file_to_image(mlx, "img/opps_1.xpm", &width, &height);
	vars->img.monster_2 = mlx_xpm_file_to_image(mlx, "img/opps_2.xpm", &width, &height);
	vars->img.monster_3 = mlx_xpm_file_to_image(mlx, "img/opps_3.xpm", &width, &height);
	vars->img.wall = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &width, &height);
	vars->img.player_0 = mlx_xpm_file_to_image(mlx, "img/frame_0.xpm", &width, &height);
	vars->img.player_1 = mlx_xpm_file_to_image(mlx, "img/frame_1.xpm", &width, &height);
	vars->img.player_2 = mlx_xpm_file_to_image(mlx, "img/frame_2.xpm", &width, &height);
	vars->img.door = mlx_xpm_file_to_image(mlx, "img/door.xpm", &width, &height);
	vars->img.score = mlx_xpm_file_to_image(mlx, "img/score.xpm", &width, &height);
	vars->img.exit = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &width, &height);
	if (!vars->img.empty || !vars->img.monster_1 || !vars->img.monster_2 || !vars->img.monster_3 \
		|| !vars->img.wall || !vars->img.skull_0 || !vars->img.skull_1 || !vars->img.skull_2 \
		|| !vars->img.skull_3 || !vars->img.skull_4 || !vars->img.skull_5 || !vars->img.skull_6 \
		|| !vars->img.skull_7 || !vars->img.player_0 || !vars->img.player_1 \
		|| !vars->img.player_2 || !vars->img.door || !vars->img.score || !vars->img.exit)
		close_win(vars);
}

void	find_img(t_vars *vars, t_img img, char c)
{
	static int count_ani = 0;
	static int skull_ani = 1;

	if (c == 'P')
	{
		if (count_ani == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, img.player_0, img.i, img.x);
		else if (count_ani == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, img.player_1, img.i, img.x);
		else if (count_ani == 2)
			mlx_put_image_to_window(vars->mlx, vars->win, img.player_2, img.i, img.x);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, img.player_1, img.i, img.x);
	}
	if (c == 'M')
	{
		if (count_ani == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, img.monster_1, img.i, img.x);
		else if (count_ani == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, img.monster_2, img.i, img.x);
		else if (count_ani == 2)
			mlx_put_image_to_window(vars->mlx, vars->win, img.monster_3, img.i, img.x);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, img.monster_2, img.i, img.x);
	}

	if (c == 'S')
		mlx_put_image_to_window(vars->mlx, vars->win, img.score, 0, 0);
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, img.empty, img.i, img.x);
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, img.wall, img.i, img.x);
	if (c == 'C')
	{
		if (skull_ani == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, img.skull_0, img.i, img.x);
		else if (skull_ani == 2)
			mlx_put_image_to_window(vars->mlx, vars->win, img.skull_1, img.i, img.x);
		else if (skull_ani == 3)
			mlx_put_image_to_window(vars->mlx, vars->win, img.skull_2, img.i, img.x);
		else if (skull_ani == 4)
			mlx_put_image_to_window(vars->mlx, vars->win, img.skull_3, img.i, img.x);
		else if (skull_ani == 5)
			mlx_put_image_to_window(vars->mlx, vars->win, img.skull_4, img.i, img.x);
		else if (skull_ani == 6)
			mlx_put_image_to_window(vars->mlx, vars->win, img.skull_5, img.i, img.x);
		else if (skull_ani == 7)
			mlx_put_image_to_window(vars->mlx, vars->win, img.skull_6, img.i, img.x);
		else
			mlx_put_image_to_window(vars->mlx, vars->win, img.skull_7, img.i, img.x);
	}
	if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, img.door, img.i, img.x);
	if (c == 'F')
		mlx_put_image_to_window(vars->mlx, vars->win, img.exit, img.i, img.x);
	count_ani++;
	if (count_ani > 2)
		count_ani = 0;
	skull_ani++;
	if (skull_ani >= 7)
		skull_ani = 1;
}

void	put_sprite_utils(t_vars *vars)
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

//	usleep(170000);
	clock_gettime(CLOCK_MONOTONIC, &vars->start);
	xpm_to_img(vars->mlx, vars);
	vars->img.x = 0;
	vars->img.i = 120;
	put_sprite_utils(vars);
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
	clock_gettime(CLOCK_MONOTONIC, &vars->end);
	vars->elapsed = (vars->end.tv_sec - vars->start.tv_sec) + (vars->end.tv_nsec - vars->start.tv_nsec) / 1e9;

//	double frame_duration = 1.0 / FRAME_RATE;
//	if (vars->elapsed < frame_duration)
//		sleep(1);
	return (1);
}

//clock_gettime(CLOCK_MONOTONIC, &vars.start);
//
//clock_gettime(CLOCK_MONOTONIC, &vars.end);
//vars.elapsed = (vars.end.tv_sec - vars.start.tv_sec) + (vars.end.tv_nsec - vars.start.tv_nsec) / 1e9;
//
//double frame_duration = 1.0 / FRAME_RATE;
//if (vars.elapsed < frame_duration)
//sleep(1);
