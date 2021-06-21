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

static char	*get_sprite_color(t_tex *tex, int x, int y, int cubesize)
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


void	draw_cube(t_conf *conf, int startx, int starty)
{
	int		x;
	int		y;
	char	*color;
	t_tex	*tex;

	tex = choose_texture(conf, conf->map[starty][startx]);
	y = 0;
	while (y < conf->cube_size)
	{
		x = 0;
		while (x < conf->cube_size)
		{
			if (tex)
				color = get_sprite_color(tex, x, y, conf->cube_size);
			if (color != NULL)
			{
				if (*(unsigned int *)color != 0xff0000)
					my_mlx_pixel_put(&conf->img, (startx * conf->cube_size) + x, (starty * conf->cube_size) + y, *(unsigned int *)color);
				else
					my_mlx_pixel_put(&conf->img, (startx * conf->cube_size) + x, (starty * conf->cube_size) + y, 0xffff);
			}
			x++;
		}
		y++;
	}
}
