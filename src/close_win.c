/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:08:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/10 14:02:54 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 'w' || keycode == 'a' || keycode == 'd' || keycode == 's')
		player_move(keycode, vars);
	if (keycode == 65307)
	{
		ft_putnbr_fd((int)vars->move, 1);
		mlx_loop_end(vars->mlx);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	return (0);
}

int	close_win(t_vars *vars)
{
	ft_putnbr_fd((int)vars->move, 1);
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
