/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:24:05 by grebrune          #+#    #+#             */
/*   Updated: 2024/01/11 13:24:05 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	tab_len(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

char	**tab_dup(char **tab)
{
	size_t	x;
	char	**tmp;

	x = 0;
	tmp = ft_calloc(sizeof(char *), tab_len(tab) + 1);
	while (tab[x])
	{
		tmp[x] = ft_strdup(tab[x]);
		x++;
	}
	tmp[x] = NULL;
	return (tmp);
}
