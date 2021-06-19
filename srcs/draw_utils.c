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

// int	my_mlx_pixel_get(t_tex t, float x, int y)
// {
// 	int color;
// 	int *int_addr;

// 	int_addr = (int*)t.addr;
// 	color = int_addr[y * t.width + (int)(x * t.width)];
// 	return (color);
// }

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
