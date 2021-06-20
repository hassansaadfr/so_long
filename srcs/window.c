#include "so_long.h"

static void	init_keys_struct(t_keys *key)
{
	key->north = 0;
	key->south = 0;
	key->east = 0;
	key->west = 0;
}

static void	load_texture(t_conf *conf, t_tex *t, char *path)
{
	t->img = mlx_xpm_file_to_image(conf->mlx, path, &t->width, &t->height);
	t->addr = mlx_get_data_addr(t->img, &t->bits_per_pixel,
			&t->line_length, &t->endian);
}

static void	load_all_textures(t_conf **conf)
{
	load_texture(*conf, &(*conf)->avatar, "textures/avatar.xpm");
	load_texture(*conf, &(*conf)->item, "textures/item.xpm");
	load_texture(*conf, &(*conf)->wall, "textures/wall.xpm");
	load_texture(*conf, &(*conf)->door, "textures/door.xpm");
}

static void	init_hooks(t_conf *conf)
{
	mlx_hook(conf->win, 2, 1L << 0, keypress, conf);
	mlx_hook(conf->win, 3, 1L << 1, keyrelease, conf);
	mlx_hook(conf->win, 10, 1L << 21, focus_window, conf);
	mlx_hook(conf->win, 33, 1L << 17, exit_game, conf);
}

void	init_window(t_conf *conf)
{
	conf->mlx = mlx_init();
	init_keys_struct(&conf->keys);
	get_screen_size(conf->mlx, &conf->screen_res.x, &conf->screen_res.y);
	conf->win = mlx_new_window(conf->mlx,
			conf->screen_res.x, conf->screen_res.y, "so_long");
	conf->img.img = mlx_new_image(conf->mlx,
			conf->screen_res.x, conf->screen_res.y);
	conf->img.addr = mlx_get_data_addr(conf->img.img, &conf->img.bits_per_pixel,
			&conf->img.line_length, &conf->img.endian);
	load_all_textures(&conf);
	init_hooks(conf);
	conf->cube_size = get_cube_size(conf->screen_res, conf->map);
	mlx_loop_hook(conf->mlx, loop_hook, conf);
}
