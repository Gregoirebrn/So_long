/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:39:19 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/30 15:58:32 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_add(size_t *len, ssize_t *err_write, size_t *i)
{
	*len += *err_write;
	*i += 2;
}

static int	ft_printchar(const char *str, size_t *i, size_t *len)
{
	if (-1 == ft_putchar(str[*i]))
		return (-1);
	*i += 1;
	*len += 1;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	ssize_t	err_write;
	va_list	lst;

	len = 0;
	i = 0;
	if (!str)
		return (0);
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			err_write = ft_find_type(str[i + 1], lst);
			if (err_write == (-1))
				return (va_end(lst), -1);
			ft_add(&len, &err_write, &i);
		}
		else
			if (-1 == ft_printchar(str, &i, &len))
				return (-1);
	}
	return (va_end(lst), (int)len);
}
