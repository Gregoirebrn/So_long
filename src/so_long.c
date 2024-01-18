/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:23:49 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/18 13:39:04 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_maker(t_vars *vars, t_val *val)
{
	int		fd;
	char	line[1024];
	size_t	i;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error : Can't open file.", 1), 1);
	if (0 > read(fd, NULL, 0))
		return (ft_putstr_fd("Error : Can't read file.", 1), 1);
	i = read(fd, line, 1024);
	line[i] = '\0';
	vars->map = ft_split(line, '\n');
	if (check_border(vars->map) || check_val(vars->map, val) || \
	check_path(vars->map, vars))
		return (1);
	vars->val = val;
	return (close(fd), ft_putstr_fd("Good!\n", 1), 0);
}

void	make_window(t_vars vars)
{
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 780, 300, "So_long");
	put_sprite(vars);
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_win, &vars);
	mlx_loop(vars.mlx);
}

int	main(void)
{
	t_vars	vars;
	t_val	val;
	int		error;

	ft_bzero(&vars, sizeof(vars));
	error = map_maker(&vars, &val);
	if (error == 1)
		return (1);
	make_window(vars);
	return (0);
}
