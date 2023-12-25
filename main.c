/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:11:23 by grebrune          #+#    #+#             */
/*   Updated: 2023/12/21 18:48:26 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		fd;
	char	line[1024];
	char    **tab;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error : Can't open file.", 1), 0);
	if ( 0 > read(fd ,line, 1024))
		return (ft_putstr_fd("Error : Can't read file.", 1), 0);
    tab = ft_split(line, '\n');
    if (0 != check_border(tab) || check_val(tab) != 0 || check_path(tab) != 0)
		return (1);
	return (close(fd), ft_putstr_fd("Good!\n", 1), 0);
}


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
