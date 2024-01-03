/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:23:49 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/03 16:01:52 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 65307 || keycode == 'a')
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_sprite(void *mlx, char **map)
{
	int     i;
	int     x;
	void    *img;
	static const char *tab[4] = {"wall.png", "empty.png", "collect.png", "door.png"};
	int		img_width;
	int		img_height;

	x = 0;
	while (map[x])
	{
		i = 0;
		while (map[x][i])
		{
			img = mlx_xpm_file_to_image(mlx, tab[(map[x][i]) - 48], &img_width, &img_height);
			i++;
		}
		x++;
	}
	my_mlx_pixel_put(img, img_width, img_height, 0x00FF0000);
}

char    **map_maker(void)
{
	int		fd;
	char	line[1024];
	char    **tab;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error : Can't open file.", 1), NULL);
	if ( 0 > read(fd ,line, 1024))
		return (ft_putstr_fd("Error : Can't read file.", 1), NULL);
	tab = ft_split(line, '\n');
	if (0 != check_border(tab) || check_val(tab) != 0 || check_path(tab) != 0)
		return (NULL);
	return (close(fd), ft_putstr_fd("Good!\n", 1), tab);
}
// have to close win with cross
// print map in win with put_sprite
int	main(void)
{
	char **tab;
	t_data	img;
	t_vars vars;

	tab = map_maker();
	if (!tab)
		return (1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "So_long");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, \
			&img.endian);
	put_sprite(vars.mlx, tab);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, ft_hook, &vars);
	mlx_mouse_hook(vars.win, ft_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
