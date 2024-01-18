/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:25:00 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/18 13:42:07 by grebrune         ###   ########.fr       */
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
	img->score = mlx_xpm_file_to_image(mlx, "img/score.xpm", &width, &height);
	img->exit = mlx_xpm_file_to_image(mlx, "img/exit.xpm", &width, &height);
}

void	find_img(t_vars *vars, t_img img, char c)
{
	if (c == 'S')
		mlx_put_image_to_window(vars->mlx, vars->win, img.score, 0, 0);
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

	xpm_to_img(vars.mlx, &vars.img);
	vars.img.x = 0;
	vars.img.i = 120;
	put_sprite_utils(&vars);
	find_img(&vars, vars.img, 'S');
	mlx_string_put(vars.mlx, vars.win, 4, 25, 0xFFFFFFFF, "MOVES :");
	str = ft_itoa(vars.move);
	if (!str)
	{
		ft_putstr_fd("Error\nMalloc crash, abort program", 1);
		close_win(&vars);
	}
	mlx_string_put(vars.mlx, vars.win, 50, 25, 0xFFFFFFFF, str);
	free(str);
	close_img(&vars);
}
