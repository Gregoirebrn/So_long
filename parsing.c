/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:58:30 by grebrune          #+#    #+#             */
/*   Updated: 2023/12/15 21:13:37 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    check_border(char **tab)
{
    size_t  y;
    size_t  x;

    y = 0;
    x = ft_strlen(tab[0]);
    while (tab[y])
    {
        if (tab[y][0] != '1' || tab[y][x - 1] != '1')
            return (1);
        y++;
    }
    x = 0;
    while (tab[0][x])
    {
        if (tab[0][x] != '1' || tab[y - 1][x] != '1')
            return (1);
        x++;
    }
    if (x == y)
        return (1);
    return (0);
}

int check_val(char **tab)
{
    size_t  y;
    size_t  x;
    t_val   val;

    x = 0;
    val.p_val = 0;
    val.e_val = 0;
    val.c_val = 0;
    while (tab[x])
    {
        y = 0;
        while (tab[x][y])
        {
            if (tab[x][y] == 'P')
                val.p_val++;
            else if (tab[x][y] == 'E')
                val.e_val++;
            else if (tab[x][y] == 'C')
                val.c_val++;
            y++;
        }
        x++;
    }
    if (val.p_val != 1 || val.e_val != 1 || val.c_val < 1)
        return (1);
    return (0);
}

int     check_path(char **tab)
{
    size_t  y;
    size_t  x;
    size_t  p_y;
    size_t  p_x;
    size_t  c;

    x = 0;
    while (tab[x])
    {
        y = 0;
        while (tab[y])
        {
            if (tab[x][y] == 'P')
                if (1 == find_path(tab, y, x))
                    return (1);
            y++;
        }
        x++;
    }
    if (still_c(tab) == 1)
        return (1);
    return (0);
}
