#include "so_long.h"

int	open_map(char *path)
{
	int		fd;
	char	*ext;

	fd = -1;
	errno = 0;
	ext = ft_strrchr(path, '.');
	if (ft_strcmp(".ber", ext) != 0)
	{
		print_err(NOT_VALID_FILE);
		ft_exit_free(1);
	}
	fd = open(path, O_RDONLY);
	if (errno != 0 || fd == -1)
	{
		print_err(strerror(errno));
		ft_exit_free(1);
	}
	return (fd);
}

char	**lst_to_arr(t_list *lst)
{
	t_list	**tmp;
	char	**arr;
	int		size;
	int		i;

	i = 0;
	tmp = &lst;
	size = ft_lstsize(lst);
	arr = NULL;
	arr = ft_alloc(sizeof(char *) * (size + 1));
	while (lst)
	{
		arr[i++] = ft_strdup(lst->content);
		lst = lst->next;
	}
	arr[i] = NULL;
	ft_lstclear(tmp, NULL);
	return (arr);
}

char	**parse(char *path)
{
	t_list	*map;
	int		ret_gnl;
	int		fd;
	char	*line;

	map = 0;
	line = NULL;
	fd = open_map(path);
	ret_gnl = 1;
	while (ret_gnl > 0)
	{
		ret_gnl = get_next_line(fd, &line);
		if (line != NULL && ft_strlen(line) > 0)
		{
			ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
			ft_free_ptr((void **)&line);
		}
	}
	close(fd);
	return (lst_to_arr(map));
}
