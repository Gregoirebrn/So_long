/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:01:49 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/03 18:23:10 by grebrune         ###   ########.fr       */
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
}	t_vars;

char	**map_maker(void);
int		check_border(char **tab);
int		check_val(char **tab);
int		check_path(char **tab);
void	find_path(char **tab, size_t y, size_t x);
int		still_c(char **tab);
size_t	tab_len(char **tab);
int		ft_hook(int keycode, t_vars *vars);

char	*find_val(char **map, int x, int i);
void	put_sprite(void *mlx, char **tab, void *img);

#endif