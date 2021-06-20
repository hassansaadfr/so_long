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

void	game(t_conf *conf)
{
	extract_positions(conf);
	init_window(conf);
	mlx_loop(conf->mlx);
}
