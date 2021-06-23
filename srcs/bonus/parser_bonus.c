#include "so_long_bonus.h"

static t_list	*init_item_node(int x, int y)
{
	t_list	*node;
	t_item	*item;
	t_coord	pos;

	item = ft_alloc(sizeof(t_item));
	pos.x = x;
	pos.y = y;
	item->item_pos = pos;
	node = ft_lstnew(item);
	return (node);
}

void	get_player_pos(char **map, t_coord *player_pos)
{
	t_coord	pos;
	int		found;

	pos.x = 0;
	pos.y = 0;
	found = 0;
	while (map[pos.y])
	{
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == 'P')
			{
				found++;
				player_pos->x = pos.x;
				player_pos->y = pos.y;
			}
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	if (found == 0)
		ft_exit_free(print_err(MISSING_PLAYER_POS));
	else if (found > 1)
		ft_exit_free(print_err(MULTIPLE_PLAYER_POS));
}

void	get_items_pos(t_conf *conf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (conf->map[y])
	{
		while (conf->map[y][x])
		{
			if (conf->map[y][x] == 'C')
				ft_lstadd_back(&conf->item_list,
					init_item_node(x, y));
			else if (conf->map[y][x] == 'E')
				ft_lstadd_back(&conf->exit_list,
					init_item_node(x, y));
			x++;
		}
		x = 0;
		y++;
	}
}

char	**parse(char *path)
{
	t_list	*map;
	int		ret_gnl;
	int		fd;
	char	*line;

	map = 0;
	line = NULL;
	fd = open_file(path);
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
