#include "so_long.h"

static void	write_move(t_conf *conf, char *str)
{
	(void)conf;
	ft_putstr_fd(str, STDOUT_FILENO);
}

void	move_north(t_conf *conf)
{
	write_move(conf, "Move north");
}

void	move_south(t_conf *conf)
{
	write_move(conf, "Move south");
}

void	move_east(t_conf *conf)
{
	write_move(conf, "Move east");
}

void	move_west(t_conf *conf)
{
	write_move(conf, "Move west");
}
