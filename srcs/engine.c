#include "so_long.h"

static void	extract_positions(t_conf *conf)
{
	conf->player_pos = ft_alloc(sizeof(t_coord));
	get_player_pos(conf->map, conf->player_pos);
	conf->item_list = NULL;
	conf->exit_list = NULL;
	get_items_pos(conf);
	if (ft_lstsize(conf->exit_list) == 0)
		ft_exit_free(print_err(NO_EXIT_GATE));
}

void	draw_frame(t_conf *conf)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (conf->map[y])
	{
		while (conf->map[y][x])
		{
			draw_cube(conf, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	game(t_conf *conf)
{
	extract_positions(conf);
	init_window(conf);
	draw_frame(conf);
	ft_draw_img(conf, 0, 0);
	mlx_loop(conf->mlx);
}
