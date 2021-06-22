#include "so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_draw_img(t_conf *conf, int x, int y)
{
	mlx_put_image_to_window(conf->mlx, conf->win, conf->img.img, x, y);
}

int	my_mlx_pixel_get(t_tex t, int x, int y)
{
	int	color;
	int	*int_addr;

	int_addr = (int *)t.addr;
	color = int_addr[y * t.width + (x * t.width)];
	return (color);
}

char	*get_sprite_color(t_tex *tex, int x, int y, int cubesize)
{
	int		txt_x;
	int		txt_y;
	char	*color;

	txt_x = 0;
	txt_y = 0;
	txt_x = tex->width / (100 / (((double)x / cubesize) * 100.0));
	txt_y = tex->height / (100 / (((double)y / cubesize) * 100.0));
	color = tex->addr + ((4 * tex->width * txt_y) + (4 * txt_x));
	return (color);
}

int	color_trans(t_tex *tex, char *color)
{
	int		transparancy;
	int		actual;
	int		background;

	background = 0xFFFFFF;
	if (!tex)
		return (background);
	transparancy = my_mlx_pixel_get(*tex, 0, 0);
	actual = *(int *)color;
	if (actual == transparancy)
		return (background);
	else
		return (actual);
}
