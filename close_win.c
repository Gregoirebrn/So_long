/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:08:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/08 17:08:30 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_loop_end(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}

int	close_win(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
