/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:58:30 by grebrune          #+#    #+#             */
/*   Updated: 2023/12/19 19:55:39 by grebrune         ###   ########.fr       */
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
            return (ft_putstr_fd("Error : Wall of the map are incomplete\n", 1), 1);
        y++;
    }
    x = 0;
    while (tab[0][x])
    {
        if (tab[0][x] != '1' || tab[y - 1][x] != '1')
            return (ft_putstr_fd("Error : Wall of the map are incomplete\n", 1), 1);
        x++;
    }
    if (x == y)
        return (ft_putstr_fd("Error : Map is not a rectangle\n", 1), 1);
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
        return (ft_putstr_fd("Error : Missing item in the map\n", 1), 1);
    return (0);
}

int     still_c(char **tab)
{
    size_t  y;
    size_t  x;

    x = 0;
    while (tab[x])
    {
        y = 0;
        while (tab[x][y])
        {
            if (tab[x][y] == 'C')
                return (ft_putstr_fd("Error : All collectibles are not reachable.", 1), 1);
            y++;
        }
        x++;
    }
    return (0);
}

int find_path(char **tab, size_t y, size_t x)
{
    if (tab[x][y] == 'P')
        return (0);
    if (tab[x][y] != '1')
    {
        find_path(tab, y - 1, x);
        find_path(tab, y, x - 1);
        find_path(tab, y + 1, x);
        find_path(tab, y, x + 1);
    }
    return (1);
}

size_t  tab_len(char **tab)
{
    size_t  i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

char    **tab_dup(char **tab)
{
    size_t  x;
    char    **tmp;

    x = 0;
    tmp = ft_calloc(sizeof(char *), tab_len(tab));
    while (tab[x])
    {
        tmp[x] = ft_strdup(tab[x]);
        x++;
    }
    return (tmp);
}

int     check_path(char **tab)
{
    size_t  y;
    size_t  x;
    char    **tmp;

    x = 0;
    tmp = tab_dup(tab);
    while (tab[x])
    {
        y = 0;
        while (tab[y])
        {
            if (tab[x][y] == 'P')
                if (1 == find_path(tmp, y, x))
                    return (ft_putstr_fd("Error : Map does not contain a valid path\n", 1), 1);
            y++;
        }
        x++;
    }
    return (still_c(tab));
}
