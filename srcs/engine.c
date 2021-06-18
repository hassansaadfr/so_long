#include "so_long.h"

t_coord	*get_player_pos(char **map)
{
	t_coord	*player_pos;
	int		x;
	int		y;
	int		found;

	x = 0;
	y = 0;
	found = 0;
	player_pos = ft_alloc(sizeof(player_pos));
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				if (found == 1)
				{
					print_err(MULTIPLE_PLAYER_POS);
					ft_exit_free(1);
				}
				found++;
				player_pos->x = x;
				player_pos->y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (found == 1)
		return (player_pos);
	print_err(MISSING_PLAYER_POS);
	ft_exit_free(1);
	return (NULL);
}

void	game(t_conf *conf)
{
	conf->player_pos = get_player_pos(conf->map);
}
