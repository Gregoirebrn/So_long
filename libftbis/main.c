
#include "libft.h"
#include <stdio.h>

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
	printf("%s", (char *)lst->content);
	while (line)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		lst = ft_lstnew((void *)line);
		printf("%s", (char *)lst->content);
		ft_lstadd_back(&head, lst);
		lst = lst->next;
	}
	lst->next = NULL;
	close(fd);
	return (0);
}
