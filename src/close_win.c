/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:08:30 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/24 15:24:46 by grebrune         ###   ########.fr       */
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
	double	elapsed;
	int		min;
	int		sec;

	if (keycode == 'w' || keycode == 'a' || keycode == 'd' || keycode == 's')
		player_move(keycode, vars);
	if (keycode == 65307)
		close_win(vars);
	if (vars->map[vars->x][vars->y] == vars->map[vars->val->x][vars->val->y] \
		&& vars->val->c_val == 0)
	{
		time(&vars->t1);
		elapsed = difftime(vars->t1, vars->t0);
		min = (int)elapsed / 60;
		sec = (int)elapsed % 60;
		ft_printf("You Win in %d,%d min!\n", min, sec);
		close_win(vars);
	}
	return (0);
}

void	destroy_skull(t_vars *vars)
{
	if (vars->img.skull_0)
		mlx_destroy_image(vars->mlx, vars->img.skull_0);
	if (vars->img.skull_1)
		mlx_destroy_image(vars->mlx, vars->img.skull_1);
	if (vars->img.skull_2)
		mlx_destroy_image(vars->mlx, vars->img.skull_2);
	if (vars->img.skull_3)
		mlx_destroy_image(vars->mlx, vars->img.skull_3);
	if (vars->img.skull_4)
		mlx_destroy_image(vars->mlx, vars->img.skull_4);
	if (vars->img.skull_5)
		mlx_destroy_image(vars->mlx, vars->img.skull_5);
	if (vars->img.skull_6)
		mlx_destroy_image(vars->mlx, vars->img.skull_6);
	if (vars->img.skull_7)
		mlx_destroy_image(vars->mlx, vars->img.skull_7);
}

void	close_img(t_vars *vars)
{
	if (vars->img.door)
		mlx_destroy_image(vars->mlx, vars->img.door);
	if (vars->img.monster_1)
		mlx_destroy_image(vars->mlx, vars->img.monster_1);
	if (vars->img.monster_2)
		mlx_destroy_image(vars->mlx, vars->img.monster_2);
	if (vars->img.monster_3)
		mlx_destroy_image(vars->mlx, vars->img.monster_3);
	if (vars->img.score)
		mlx_destroy_image(vars->mlx, vars->img.score);
	if (vars->img.wall)
		mlx_destroy_image(vars->mlx, vars->img.wall);
	if (vars->img.exit)
		mlx_destroy_image(vars->mlx, vars->img.exit);
	if (vars->img.player_0)
		mlx_destroy_image(vars->mlx, vars->img.player_0);
	if (vars->img.player_1)
		mlx_destroy_image(vars->mlx, vars->img.player_1);
	if (vars->img.player_2)
		mlx_destroy_image(vars->mlx, vars->img.player_2);
	if (vars->img.empty)
		mlx_destroy_image(vars->mlx, vars->img.empty);
}

int	close_win(t_vars *vars)
{
	ft_printf("Total moves in game : %d\n", (int)vars->move);
	ft_free(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit (0);
}
