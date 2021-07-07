#include "so_long_bonus.h"

int	open_file(char *path)
{
	int		fd;
	char	*ext;

	errno = 0;
	ext = ft_strrchr(path, '.');
	if (ext == NULL || ft_strcmp(".ber", ext) != 0)
		ft_exit_free(print_err(NOT_VALID_FILE));
	fd = open(path, __O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		ft_exit_free(print_err(MAP_IS_DIRECTORY));
	}
	errno = 0;
	fd = open(path, O_RDONLY | O_NOFOLLOW);
	if (errno != 0 || fd == -1)
	{
		if (errno == 40)
			print_err(MAP_IS_SYMLINK);
		else
			print_err(strerror(errno));
		ft_exit_free(errno);
	}
	return (fd);
}

size_t	get_arrsize(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
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

t_tex	*choose_texture(t_conf *conf, char c)
{
	if (c == 'P')
		return (&conf->avatar);
	if (c == 'E')
		return (&conf->door);
	if (c == 'C')
		return (&conf->item);
	if (c == '1')
		return (&conf->wall);
	if (c == '0')
		return (NULL);
	return (NULL);
}
