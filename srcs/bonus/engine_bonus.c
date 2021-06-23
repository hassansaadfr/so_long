#include "so_long_bonus.h"

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

void	draw_cube(t_conf *conf, int startx, int starty)
{
	t_coord	pos;
	char	*color;
	t_tex	*tex;

	tex = choose_texture(conf, conf->map[starty][startx]);
	pos.y = 0;
	while (pos.y < conf->cube_size)
	{
		pos.x = 0;
		while (pos.x < conf->cube_size)
		{
			color = "";
			if (tex)
				color = get_sprite_color(tex, pos.x, pos.y, conf->cube_size);
			if (color != NULL)
				my_mlx_pixel_put(&conf->img,
					(startx * conf->cube_size) + pos.x,
					(starty * conf->cube_size) + pos.y,
					color_trans(tex, color));
			pos.x++;
		}
		pos.y++;
	}
}

void	game(t_conf *conf)
{
	extract_positions(conf);
	conf->move_count = 0;
	init_window(conf);
	draw_frame(conf);
	ft_draw_img(conf, 0, 0);
	mlx_loop(conf->mlx);
}
