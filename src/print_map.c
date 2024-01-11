/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:25:00 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/11 13:53:29 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_to_img(void *mlx, t_img *img)
{
	int		width;
	int		height;

	img->empty = mlx_xpm_file_to_image(mlx, "img/empty.xpm", &width, &height);
	img->wall = mlx_xpm_file_to_image(mlx, "img/wall.xpm", &width, &height);
	img->knife = mlx_xpm_file_to_image(mlx, "img/knife.xpm", &width, &height);
	img->niki = mlx_xpm_file_to_image(mlx, "img/niki.xpm", &width, &height);
	img->door = mlx_xpm_file_to_image(mlx, "img/door.xpm", &width, &height);
}

void	find_img(t_vars *vars, t_img img, char c)
{
	if (c == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, img.empty, img.i, img.x);
	if (c == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, img.wall, img.i, img.x);
	if (c == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, img.knife, img.i, img.x);
	if (c == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, img.niki, img.i, img.x);
	if (c == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, img.door, img.i, img.x);
}

void	put_sprite(t_vars vars)
{
	int		i;
	int		x;
	t_img	img;

	xpm_to_img(vars.mlx, &img);
	x = 0;
	img.x = 0;
	while (vars.map[x])
	{
		i = 0;
		img.i = 0;
		while (vars.map[x][i])
		{
			find_img(&vars, img, vars.map[x][i]);
			i++;
			img.i += 60;
		}
		x++;
		img.x += 60;
	}
}
