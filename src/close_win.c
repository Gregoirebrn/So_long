/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:08:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/11 15:26:52 by grebrune         ###   ########.fr       */
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

int	key_hook(int keycode, t_vars *vars, t_val *val)
{
	if (keycode == 'w' || keycode == 'a' || keycode == 'd' || keycode == 's')
		player_move(keycode, vars, val);
	if (keycode == 65307)
		close_win(vars);
	return (0);
}

int	close_win(t_vars *vars)
{
//	ft_free(vars->map);
	ft_putnbr_fd((int)vars->move, 1);
	mlx_loop_end(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	set_to_zero(t_val *val)
{
	val->p_val = 0;
	val->e_val = 0;
	val->c_val = 0;
}
