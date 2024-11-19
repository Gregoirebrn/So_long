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

	vars->ani.frame_1 = mlx_xpm_file_to_image(mlx, "img/frame_0.xpm", &width, &height);
	vars->ani.frame_2 = mlx_xpm_file_to_image(mlx, "img/frame_1.xpm", &width, &height);
	vars->ani.frame_3 = mlx_xpm_file_to_image(mlx, "img/frame_2.xpm", &width, &height);
	vars->ani.frame_4 = mlx_xpm_file_to_image(mlx, "img/frame_3.xpm", &width, &height);

	vars->img.empty = mlx_xpm_file_to_image(mlx, "img/empty.xpm", &width, &height);
	vars->img.monster = mlx_xpm_file_to_image(mlx, "img/opps.xpm", &width, &height);
	vars->img.wall = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &width, &height);
	vars->img.knife = mlx_xpm_file_to_image(mlx, "img/knife.xpm", &width, &height);
	vars->img.niki = mlx_xpm_file_to_image(mlx, "img/niki.xpm", &width, &height);
	vars->img.door = mlx_xpm_file_to_image(mlx, "img/door.xpm", &width, &height);
	vars->img.score = mlx_xpm_file_to_image(mlx, "img/score.xpm", &width, &height);
	vars->img.exit = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &width, &height);
	if (!vars->img.empty || !vars->img.monster || !vars->img.wall || !vars->img.knife || !vars->img.niki \
	|| !vars->img.door || !vars->img.score || !vars->img.exit)
		close_win(vars);
}

void	find_img(t_vars *vars, t_img img, char c)
{
	static int count_ani = 0;

	if (c == 'S')
		mlx_put_image_to_window(vars->mlx, vars->win, img.score, 0, 0);
	if (c == 'M')
		mlx_put_image_to_window(vars->mlx, vars->win, img.monster, img.i, img.x);
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, img.empty, img.i, img.x);
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, img.wall, img.i, img.x);
	if (c == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, img.knife, img.i, img.x);
	if (c == 'P') {
		if (count_ani == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->ani.frame_1, img.i, img.x);

		if (count_ani == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->ani.frame_2, img.i, img.x);

		if (count_ani == 2)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->ani.frame_3, img.i, img.x);

		if (count_ani == 3)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->ani.frame_4, img.i, img.x);
		count_ani++;
		if (count_ani > 3)
			count_ani = 0;
	}
	if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, img.door, img.i, img.x);
	if (c == 'F')
		mlx_put_image_to_window(vars->mlx, vars->win, img.exit, img.i, img.x);
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

void	put_sprite(t_vars vars)
{
	char	*str;

	xpm_to_img(vars.mlx, &vars);
	vars.img.x = 0;
	vars.img.i = 120;
	put_sprite_utils(&vars);
	find_img(&vars, vars.img, 'S');
	mlx_string_put(vars.mlx, vars.win, 34, 10, 0xFFFFFFFF, "MOVES :");
	str = ft_itoa(vars.move);
	if (!str)
	{
		ft_putstr_fd("Error\nMalloc crash, abort program", 1);
		close_win(&vars);
	}
	mlx_string_put(vars.mlx, vars.win, 80, 10, 0xFFFFFFFF, str);
	free(str);
	close_img(&vars);
}
