#include "so_long.h"

size_t	get_arrsize(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
