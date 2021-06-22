#include "so_long.h"

static void	write_move(t_conf *conf, char *str)
{
	int		col;
	char	*move_count;
	int		x;
	int		y;

	y = 10;
	while (y < 75)
	{
		x = 0;
		while (x < 140)
			my_mlx_pixel_put(&conf->img, x++, y, 0xFFFFFF);
		y++;
	}
	move_count = ft_itoa(conf->move_count);
	col = 0x800080;
	ft_putendl_fd(str, STDOUT_FILENO);
	ft_putstr_fd("Move: ", STDOUT_FILENO);
	ft_putendl_fd(move_count, STDOUT_FILENO);
	mlx_set_font(conf->mlx, conf->win, FONT);
	mlx_string_put(conf->mlx, conf->win, 10, 40, col, str);
	mlx_string_put(conf->mlx, conf->win, 10, 70, col, "Move: ");
	mlx_string_put(conf->mlx, conf->win, 80, 70, col, move_count);
	ft_free_ptr((void **)&move_count);
}

void	move(t_conf *conf, t_coord next)
{
	char	next_pos;

	if ((next.x > 0 && next.x < (int)ft_strlen(*conf->map))
		&& (next.y > 0 && next.y < (int)get_arrsize(conf->map)))
	{
		next_pos = conf->map[next.y][next.x];
		if (next_pos == 'E')
			exit_game(conf);
		if (next_pos == '0' || next_pos == 'C')
		{
			conf->map[next.y][next.x] = 'P';
			conf->map[conf->player_pos->y][conf->player_pos->x] = '0';
			conf->player_pos->x = next.x;
			conf->player_pos->y = next.y;
			conf->move_count++;
			draw_frame(conf);
		}
	}
}

void	move_north(t_conf *conf)
{
	t_coord	pos;

	pos.x = conf->player_pos->x;
	pos.y = conf->player_pos->y - 1;
	move(conf, pos);
	write_move(conf, "Move north");
}

void	move_south(t_conf *conf)
{
	t_coord	pos;

	pos.x = conf->player_pos->x;
	pos.y = conf->player_pos->y + 1;
	move(conf, pos);
	write_move(conf, "Move south");
}

void	move_side(t_conf *conf, int side)
{
	t_coord	pos;

	if (side == LEFT)
		pos.x = conf->player_pos->x - 1;
	else
		pos.x = conf->player_pos->x + 1;
	pos.y = conf->player_pos->y;
	move(conf, pos);
	if (side == LEFT)
		write_move(conf, "Move left");
	else
		write_move(conf, "Move right");
}
