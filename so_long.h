/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:01:49 by grebrune          #+#    #+#             */
/*   Updated: 2023/12/15 19:01:09 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include "libftbis/libft.h"
#include <stdio.h>

typedef struct s_val{
    size_t  p_val;
    size_t  e_val;
    size_t  c_val;
}               t_val;

int check_border(char **tab);
int check_val(char **tab);

#endif //SO_LONG_H
