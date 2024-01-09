/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:01:49 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/09 18:13:26 by grebrune         ###   ########.fr       */
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
}	t_val;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	size_t	x;
	size_t	y;
}	t_vars;

typedef struct s_img
{
    void	*door;
    void	*wall;
    void	*niki;
    void	*empty;
    void	*knife;
}	t_img;

char	**map_maker(t_vars vars);
int		check_border(char **tab);
int		check_val(char **tab);
int		check_path(char **tab, t_vars vars);
void	find_path(char **tab, size_t y, size_t x);
int		still_c(char **tab);
size_t	tab_len(char **tab);

void    make_window(char **tab, t_vars vars);
int     close_win(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

void	put_sprite(void *mlx, void *win, char **tab);
void    xpm_to_img(void *mlx, t_img *img);

void	player_move(int keycode, t_vars *vars);
void	map_move(t_vars vars, int a, int o)

#endif
