#include "so_long.h"

int	exit_game(t_conf *conf)
{
	int		i;

	i = 0;
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

int	focus_window(t_conf *conf)
{
	conf->keys.north = 0;
	conf->keys.south = 0;
	conf->keys.east = 0;
	conf->keys.west = 0;
	return (1);
}

int	keypress(int keycode, t_conf *conf)
{
	if (keycode == ESCAPE)
		exit_game(conf);
	if (keycode == W || keycode == UP)
		conf->keys.north = 1;
	if (keycode == S || keycode == DOWN)
		conf->keys.south = 1;
	if (keycode == A || keycode == RIGHT)
		conf->keys.east = 1;
	if (keycode == D || keycode == LEFT)
		conf->keys.west = 1;
	return (keycode);
}

int	keyrelease(int keycode, t_conf *conf)
{
	if (keycode == W)
		conf->keys.north = 0;
	if (keycode == S)
		conf->keys.south = 0;
	if (keycode == A)
		conf->keys.east = 0;
	if (keycode == D)
		conf->keys.west = 0;
	return (1);
}

int	loop_hook(t_conf *conf)
{
	if (conf->keys.north)
		move_north(conf);
	if (conf->keys.south)
		move_south(conf);
	if (conf->keys.east)
		move_east(conf);
	if (conf->keys.west)
		move_west(conf);
	return (1);
}
