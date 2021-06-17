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

int	is_wall_line(char *line)
{
	while (*line)
	{
		if (*line != '1')
		{
			print_err(NOT_CLOSED);
			return (1);
		}
		line++;
	}
	return (0);
}

int	line_is_correctly_formated(t_list *map, char *line)
{
	int	lst_size;
	int	line_size;
	int	first_line_size;

	lst_size = 0;
	line_size = 0;
	if (map != NULL)
		lst_size = ft_lstsize(map);
	if (lst_size == 0)
		return (is_wall_line(line));
	else
	{
		first_line_size = ft_strlen(map->content);
		line_size = ft_strlen(line);
		if (line_size != first_line_size)
		{
			print_err(NOT_RECTANGULAR);
			return (1);
		}
	}
	return (0);
}

char	**lst_to_arr(t_list *lst)
{
	int		i;
	int		size;
	char	**arr;
	t_list	*tmp;

	tmp = lst;
	arr = NULL;
	i = 0;
	size = ft_lstsize(lst);
	if ((int)ft_strlen(lst->content) == size)
	{
		print_err(NOT_RECTANGULAR);
		ft_exit_free(1);
	}
	if (is_wall_line(ft_lstlast(lst)->content) != 0)
	{
		print_err(NOT_CLOSED);
		ft_exit_free(1);
	}
	arr = ft_alloc(sizeof(char *) * (size + 1));
	while (lst)
	{
		arr[i] = lst->content;
		i++;
		lst = lst->next;
	}
	ft_lstclear(&tmp, NULL);
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
			if (line_is_correctly_formated(map, line) == 0)
			{
				ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
				ft_free_ptr((void **)&line);
			}
			else
			{
				ft_free_ptr((void **)&line);
				close(fd);
				ft_exit_free(1);
			}
		}
	}
	close(fd);
	return (lst_to_arr(map));
}
