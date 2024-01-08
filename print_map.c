/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:25:00 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/08 17:03:34 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    xpm_to_img(void *mlx, t_img *img)
{
    int		img_width;
    int		img_height;

    img->empty = mlx_xpm_file_to_image(mlx, "empty.xpm", &img_width, &img_height);
    img->wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &img_width, &img_height);
    img->knife = mlx_xpm_file_to_image(mlx, "knife.xpm", &img_width, &img_height);
    img->niki = mlx_xpm_file_to_image(mlx, "niki.xpm", &img_width, &img_height);
    img->door = mlx_xpm_file_to_image(mlx, "door.xpm", &img_width, &img_height);
}

void    put_sprite(void *mlx, void *win, char **map)
{
    int     i;
    int     x;
    int     pixel_i;
    int     pixel_x;
    t_img   img;

    xpm_to_img(mlx, &img);
    x = 0;
    pixel_x = 0;
    while (map[x])
    {
        i = 0;
        pixel_i = 0;
        while (map[x][i])
        {
            if (map[x][i] == '0')
                mlx_put_image_to_window(mlx, win, img.empty, pixel_i, pixel_x);
            if (map[x][i] == '1')
                mlx_put_image_to_window(mlx, win, img.wall, pixel_i, pixel_x);
            if (map[x][i] == 'C')
                mlx_put_image_to_window(mlx, win, img.knife, pixel_i, pixel_x);
            if (map[x][i] == 'P')
                mlx_put_image_to_window(mlx, win, img.niki, pixel_i, pixel_x);
            if (map[x][i] == 'E')
                mlx_put_image_to_window(mlx, win, img.door, pixel_i, pixel_x);
            i++;
            pixel_i += 60;
        }
        x++;
        pixel_x += 60;
    }
}