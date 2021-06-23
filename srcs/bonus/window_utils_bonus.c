#include "so_long_bonus.h"

void	open_window(t_conf *conf)
{
	mlx_get_screen_size(conf->mlx, &conf->screen_res.x,
		&conf->screen_res.y);
	conf->cube_size = get_cube_size(conf->screen_res, conf->map);
	conf->screen_res.x = conf->cube_size * ft_strlen(*conf->map);
	conf->screen_res.y = conf->cube_size * get_arrsize(conf->map);
	conf->win = mlx_new_window(conf->mlx,
			conf->screen_res.x, conf->screen_res.y, "so_long");
	conf->img.img = mlx_new_image(conf->mlx,
			conf->screen_res.x, conf->screen_res.y);
}
