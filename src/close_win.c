/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:08:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/23 16:08:09 by grebrune         ###   ########.fr       */
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
		close_win(vars);
	if (vars->map[vars->x][vars->y] == vars->map[vars->val->x][vars->val->y] \
	&& vars->val->c_val == 0)
		close_win(vars);
	return (0);
}

void	close_img(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.door);
	mlx_destroy_image(vars->mlx, vars->img.empty);
	mlx_destroy_image(vars->mlx, vars->img.exit);
	mlx_destroy_image(vars->mlx, vars->img.niki);
	mlx_destroy_image(vars->mlx, vars->img.wall);
	mlx_destroy_image(vars->mlx, vars->img.knife);
	mlx_destroy_image(vars->mlx, vars->img.score);
}

int	close_win(t_vars *vars)
{
	ft_putstr_fd("Total moves in game : ", 1);
	ft_putnbr_fd((int)vars->move, 1);
	ft_free(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (0);
}

void	set_to_zero(t_val *val)
{
	val->p_val = 0;
	val->e_val = 0;
	val->c_val = 0;
}
