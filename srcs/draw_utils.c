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
	int color;
	int *int_addr;

	int_addr = (int*)t.addr;
	color = int_addr[y * t.width + (x * t.width)];
	return (color);
}

static int	get_sprite_color(t_tex *tex, int x, int y, int cubesize)
{
	int		x_pos_percent;
	int		y_pos_percent;
	int		x_pos_px;
	int		y_pos_px;
	int		color;

	color = 0;
	x_pos_percent = 0;
	y_pos_percent = 0;
	x_pos_px = 0;
	y_pos_px = 0;
	x_pos_percent = (x * 100) / cubesize;
	y_pos_percent = (y * 100) / cubesize;
	x_pos_px = (x_pos_percent * cubesize) / 100;
	y_pos_px = (x_pos_percent * cubesize) / 100;
	color = my_mlx_pixel_get(*tex, x_pos_px, y_pos_px);
	return (color);
}

void	draw_cube(t_conf *conf, int startx, int starty)
{
	int		x;
	int		y;
	int		color;
	t_tex	*tex;

	x = startx;
	y = starty;
	tex = choose_texture(conf, '0');
	while (x < startx + conf->cube_size)
	{
		while (y < starty + conf->cube_size)
		{
			if (tex != NULL)
				color = get_sprite_color(tex, x, y, conf->cube_size);
			else
				color = 0xff0000;
			my_mlx_pixel_put(&conf->img, x, y, color);
		}
		y = starty;
		x++;
	}
}

// int	get_sprite_pixel(t_tex t, int texture_w, t_coord offset)
// {
// 	int color;
// 	int *int_addr;

// 	int_addr = (int*)t.addr;
// 	if (offset.x < 0)
// 		offset.x = 0;
// 	color = int_addr[(texture_w * offset.y) + offset.x];
// 	return (color);
// }
