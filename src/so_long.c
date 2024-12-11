/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:23:49 by grebrune          #+#    #+#             */
/*   Updated: 2024/02/02 15:54:04 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_maker(t_vars *vars, t_val *val, char *file)
{
	int		fd;
	char	line[594];
	size_t	i;

	if (check_ber(file) == 1)
		return (ft_putstr_fd("Error\nThe file is not an .ber.", 1), 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nCan't open file.", 1), 1);
	if (0 > read(fd, NULL, 0))
		return (ft_putstr_fd("Error\nCan't read file.", 1), 1);
	i = read(fd, line, 594);
	if (i == 0)
		return (ft_putstr_fd("Error\nThe file is empty.", 1), 1);
	if (read(fd, line, 1) > 0)
		return (ft_putstr_fd("Error\nThe map is too big.", 1), 1);
	line[i] = '\0';
	vars->map = ft_split(line, '\n');
	if (check_border(vars->map) || check_val(vars->map, val) || \
	check_path(vars->map, vars))
		return (1);
	vars->val = val;
	return (close(fd), ft_putstr_fd("Enjoy!\n", 1), 0);
}

void	make_window(t_vars vars, t_val val)
{
	gettimeofday(&vars.start, NULL);
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
	{
		ft_putstr_fd("Error\nThe mlx has crash.", 1);
		ft_free(vars.map);
		return ;
	}
	vars.win = mlx_new_window(vars.mlx, 60 * val.wy, 60 * val.wx, "So_long");
	mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 0, close_win, &vars);
	mlx_loop_hook(vars.mlx, put_sprite, (void *)&vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	t_val	val;
	int		error;

	if (ac != 2)
		return (ft_putstr_fd("Error\nYou forgot the map.", 1), 1);
	ft_bzero(&vars, sizeof(vars));
	error = map_maker(&vars, &val, av[1]);
	if (error == 1)
		return (1);
	make_window(vars, val);
	return (0);
}
