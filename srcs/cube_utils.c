#include "so_long.h"

int	get_cube_size(t_coord res, char **map)
{
	int	sizex;
	int	sizey;

	sizex = 0;
	sizey = 0;
	sizex = res.x / (int)ft_strlen(*map);
	sizey = res.y / (int)get_arrsize(map);
	if (sizex < sizey)
		return (sizex);
	return (sizey);
}
