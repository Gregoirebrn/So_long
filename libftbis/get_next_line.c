/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:42:32 by grebrune          #+#    #+#             */
/*   Updated: 2023/12/14 20:59:32 by grebrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_charcmp(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
		{
			if (i == 0)
				return (i + 1);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

char	*read_line(int fd, char *line, char **next_line)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	i;

	i = 1;
	while (i > 0)
	{
		if (ft_charcmp(line, '\n'))
			return (*next_line = ft_strnext_line(line), ft_strcut(line));
		i = read(fd, buff, BUFFER_SIZE);
		if (i <= 0 && (!line))
			return (NULL);
		if (line && i == 0)
			return (*next_line = NULL, ft_lastline(line));
		buff[i] = '\0';
		line = ft_freenjoin(line, buff);
		if (!line)
			return (NULL);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next_line = NULL;

	line = next_line;
	if (read(fd, NULL, 0) < 0)
		return (free(line), next_line = NULL);
	return (read_line(fd, line, &next_line));
}

int	main(void)
{
	int		fd;
	char	*line;
	t_list	*lst;
	t_list	*head;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error : Can't open file.", 1), 0);
	line = get_next_line(fd);
	lst = ft_lstnew((void *)line);
	while (line)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		lst = ft_lstnew((void *)line);
		ft_lstadd_back(&head, lst);
		lst = lst->next;
	}
	lst->next = NULL;
	close(fd);
	return (0);
}
