#include "so_long_bonus.h"

int	get_cube_size(t_coord res, char **map)
{
	t_coord	size;
	int		len_line;
	int		len_arr;

	len_line = ft_strlen(*map);
	len_arr = get_arrsize(map);
	size = (t_coord){.x = res.x / len_line, .y = res.y / len_arr};
	if (size.x <= size.y)
	{
		if (size.y * len_line > res.x)
			size.y = (res.x / len_line) - 1;
	}
	else
	{
		if (size.x * len_arr > res.y)
			size.x = (res.y / len_arr) - 1;
	}
	if (size.x < size.y)
	{
		if (size.x < 1)
			return (1);
		return (size.x);
	}
	return (size.y);
}
