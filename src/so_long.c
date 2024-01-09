/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:23:49 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/09 19:41:20 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_maker(t_vars *vars)
{
	int		fd;
	char	line[1024];
	char	**tab;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error : Can't open file.", 1), NULL);
	if (0 > read(fd, line, 1024))
		return (ft_putstr_fd("Error : Can't read file.", 1), NULL);
	tab = ft_split(line, '\n');
	if (0 != check_border(tab) || check_val(tab) != 0 || check_path(tab, vars) != 0)
		return (NULL);
	return (close(fd), ft_putstr_fd("Good!\n", 1), tab);
}

void    make_window(char **tab, t_vars vars)
{
	t_data	img;

	vars.map = tab;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "So_long");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, \
	&img.endian);
    put_sprite(vars.mlx, vars.win, tab);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
    mlx_hook(vars.win, 17, 1L<<0, close_win, &vars);
    mlx_mouse_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
}

int	main(void)
{
    char	**tab;
	t_vars	vars;

	ft_bzero(&vars, sizeof(vars));
    tab = map_maker(&vars);
    if (!tab)
        return (1);
    make_window(tab, vars);
    return (0);
}
