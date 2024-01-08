/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:11:23 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/03 18:47:17 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*find_val(char **map, int x, int i)
{
	static const char	*tab[4] = {"wall.png", "empty.png", \
	"collect.png", "door.png"};
	int					val;

	val = map[x][i] - 48;
	return ((char *)tab[val]);
}

void	put_sprite(void *mlx, char **map, void *img)
{
	int	i;
	int	x;
	int	img_width;
	int	img_height;

	x = 0;
	while (map[x])
	{
		i = 0;
		while (map[x][i])
		{
			img = mlx_xpm_file_to_image(mlx, find_val(map, x, i), &img_width, &img_height);
			i++;
		}
		x++;
	}
}

int	main(void)
{
	void *mlx;
	void *img;
	char *relative_path = "./wall.xpm";
	int img_width;
	int img_height;

	vars.mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "So_long");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	put_sprite(vars.mlx, tab, img.img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, ft_hook, &vars);
	mlx_mouse_hook(vars.win, ft_hook, &vars);
	mlx_loop(vars.mlx);
}


//int	main(void)
//{
//	int		fd;
//	char	line[1024];
//	char	**tab;
//
//	fd = open("map.ber", O_RDONLY);
//	if (fd == -1)
//		return (ft_putstr_fd("Error : Can't open file.", 1), 0);
//	if (0 > read(fd ,line, 1024))
//		return (ft_putstr_fd("Error : Can't read file.", 1), 0);
//	tab = ft_split(line, '\n');
//	if (0 != check_border(tab) || check_val(tab) != 0 || check_path(tab) != 0)
//		return (1);
//	return (close(fd), ft_putstr_fd("Good!\n", 1), 0);
//}


//#include "mlx_linux/mlx.h"
//#include <stdio.h>
//
//typedef struct s_vars {
//	void	*mlx;
//	void	*win;
//}				t_vars;
//
//int	key_hook(int keycode, t_vars *vars)
//{
//	if (keycode == 'w')
//		printf("Hello from key_hook!\n");
//	return (0);
//}
//
//int	main(void)
//{
//	t_vars	vars;
//
//	vars.mlx = mlx_init();
//	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
//	mlx_key_hook(vars.win, key_hook, &vars);
//	mlx_loop(vars.mlx);
//}
