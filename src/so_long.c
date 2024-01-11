/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:23:49 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/11 16:12:23 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**map_maker(t_vars *vars, t_val *val)
{
	int		fd;
	char	line[1024];
	char	**tab;
	size_t	i;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error : Can't open file.", 1), NULL);
	if (0 > read(fd, NULL, 0))
		return (ft_putstr_fd("Error : Can't read file.", 1), NULL);
	i = read(fd, line, 1024);
	line[i] = '\0';
	tab = ft_split(line, '\n');
	if (check_border(tab) || check_val(tab, val) || check_path(tab, vars))
		return (NULL);
	return (close(fd), ft_putstr_fd("Good!\n", 1), tab);
}

void	make_window(char **tab, t_vars vars, t_val val)
{
	t_data	img;

	vars.map = tab;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 780, 300, "So_long");
	img.img = mlx_new_image(vars.mlx, 780, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	put_sprite(vars);
	printf("----+++---%zu---+++---", val.c_val);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_win, &vars);
	if (vars.map[vars.x][vars.y] == 'F')
		close_win(&vars);
	mlx_loop(vars.mlx);
}

int	main(void)
{
	char	**tab;
	t_vars	vars;
	t_val	val;

	ft_bzero(&vars, sizeof(vars));
	tab = map_maker(&vars, &val);
	if (!tab)
		return (1);
	make_window(tab, vars, val);
	return (ft_free(tab), 0);
}
