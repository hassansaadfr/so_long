#include "so_long_bonus.h"

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

void	init_window(t_conf *conf)
{
	conf->mlx = mlx_init();
	open_window(conf);
	conf->img.addr = mlx_get_data_addr(conf->img.img, &conf->img.bits_per_pixel,
			&conf->img.line_length, &conf->img.endian);
	load_all_textures(&conf);
	mlx_hook(conf->win, 33, 1L << 17, exit_game, conf);
	mlx_key_hook(conf->win, keypress, conf);
}
