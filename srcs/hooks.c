#include "so_long.h"

int	exit_game(t_conf *conf)
{
	mlx_destroy_image(conf->mlx, conf->img.img);
	mlx_destroy_image(conf->mlx, conf->avatar.img);
	mlx_destroy_image(conf->mlx, conf->item.img);
	mlx_destroy_image(conf->mlx, conf->wall.img);
	mlx_destroy_image(conf->mlx, conf->door.img);
	mlx_destroy_window(conf->mlx, conf->win);
	mlx_destroy_display(conf->mlx);
	mlx_loop_end(conf->mlx);
	free(conf->mlx);
	ft_exit_free(0);
	return (0);
}

int	keypress(int keycode, t_conf *conf)
{
	if (keycode == ESCAPE)
		exit_game(conf);
	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT
		|| keycode == W || keycode == S
		|| keycode == A || keycode == D)
		move_player(conf, keycode);
	return (keycode);
}
