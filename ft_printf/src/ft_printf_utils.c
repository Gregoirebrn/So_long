/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:03:16 by grebrune          #+#    #+#             */
/*   Updated: 2023/11/29 13:17:39 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static size_t	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		if (-1 == write(1, &str[i], 1))
			return (-1);
		i++;
	}
	return (i);
}

static ssize_t	ft_addr(size_t nbr, char *base, ssize_t *parse)
{
	if ((char *)nbr == NULL)
	{
		*parse = ft_putstr("(nil)");
		return (*parse);
	}
	*parse = ft_putstr("0x");
	if (*parse == -1)
		return (*parse);
	return (ft_putnbr_addr(nbr, base, parse));
}

ssize_t	ft_find_type(const char c, va_list lst)
{
	ssize_t	i;

	i = 0;
	if (c == 'c')
		return (ft_putchar((unsigned char)va_arg(lst, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(lst, char *)));
	else if (c == 'p')
		return (ft_addr((size_t)va_arg(lst, size_t), "0123456789abcdef", &i));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_b((int)va_arg(lst, int), "0123456789", &i));
	else if (c == 'u')
		ft_putnbr_b(va_arg(lst, unsigned int), "0123456789", &i);
	else if (c == 'x')
		ft_putnbr_b(va_arg(lst, unsigned int), "0123456789abcdef", &i);
	else if (c == 'X')
		ft_putnbr_b(va_arg(lst, unsigned int), "0123456789ABCDEF", &i);
	if (c == '%')
		i += ft_putchar('%');
	return (i);
}
