#include "so_long_bonus.h"

static void	print_move(t_conf *conf, char *str)
{
	int		color;
	char	*move_count;
	int		x;
	int		y;

	y = 10;
	while (y < 75 && y < conf->screen_res.y)
	{
		x = 0;
		while (x < 140 && x < conf->screen_res.x)
			my_mlx_pixel_put(&conf->img, x++, y, 0xFFFFFF);
		y++;
	}
	move_count = ft_itoa(++conf->move_count);
	color = 0x800080;
	mlx_set_font(conf->mlx, conf->win, "-sony-*-*-*-*-*-24-*-*-*-*-*-*-*");
	mlx_string_put(conf->mlx, conf->win, 10, 40, color, str);
	mlx_string_put(conf->mlx, conf->win, 10, 70, color, "Move: ");
	mlx_string_put(conf->mlx, conf->win, 80, 70, color, move_count);
	ft_free_ptr((void **)&move_count);
}

static void	write_move(t_conf *conf, char *str)
{
	ft_putendl_fd(str, STDOUT_FILENO);
	ft_putstr_fd("Move: ", STDOUT_FILENO);
	ft_putnbr_fd(++conf->move_count, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	draw_frame(conf);
	print_move(conf, str);
	ft_draw_img(conf, 0, 0);
}
