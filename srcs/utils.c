#include "so_long.h"

int	open_file(char *path)
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
