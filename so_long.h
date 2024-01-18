/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:01:49 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/18 13:13:44 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include "libftbis/libft.h"
# include "mlx_linux/mlx.h"
# include <stdio.h>

typedef struct s_val
{
	size_t	p_val;
	size_t	e_val;
	size_t	c_val;
	size_t	x;
	size_t	y;
}	t_val;

typedef struct s_img
{
	void	*door;
	void	*wall;
	void	*niki;
	void	*empty;
	void	*knife;
	void	*score;
	void	*exit;
	int		i;
	int		x;
}	t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	size_t	x;
	size_t	y;
	int		move;
	t_val	*val;
	t_img	img;
}	t_vars;

int		map_maker(t_vars *vars, t_val *val);
int		check_border(char **tab);
int		check_val(char **tab, t_val *val);
void	check_val_utils(char **tab, t_val *val, size_t x, size_t y);
int		check_path(char **tab, t_vars *vars);
void	find_path(char **tab, size_t y, size_t x);
int		still_c(char **tab);
size_t	tab_len(char **tab);
char	**tab_dup(char **tab);

void	make_window(t_vars vars);
int		close_win(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	ft_free(char **tab);
void	close_img(t_vars *vars);
void	set_to_zero(t_val *val);

void	put_sprite(t_vars vars);
void	end_game(t_vars vars, t_val val);
void	xpm_to_img(void *mlx, t_img *img);
void	find_img(t_vars *vars, t_img img, char c);

void	player_move(int keycode, t_vars *vars);
void	map_move(t_vars *vars, int y, int x);

#endif
