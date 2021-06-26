#include "so_long_bonus.h"

static void	is_valid_characters(char c)
{
	int		out;

	out = 0;
	out = ft_strchr("01CEP", c) == NULL;
	if (out == 1)
		ft_exit_free(print_err(INVALID_CHARACTER));
}

static void	is_correct_wall_line(char *line)
{
	while (*line)
	{
		if (*line != '1')
		{
			print_err(NOT_CLOSED);
			ft_exit_free(1);
		}
		line++;
	}
}

static void	is_correct_middle_line(char *line)
{
	int	i;
	int	line_size;

	if (line == NULL || ft_strlen(line) == 0)
		ft_exit_free(print_err(NOT_RECTANGULAR));
	i = 0;
	line_size = ft_strlen(line) - 1;
	while (line[i])
	{
		if (i == 0 || i == line_size)
		{
			if (line[i] != '1')
				ft_exit_free(print_err(NOT_CLOSED));
		}
		else
			is_valid_characters(line[i]);
		i++;
	}
}

void	is_correct_map(char **map)
{
	size_t	i;
	size_t	line_width;
	size_t	map_size;

	i = 0;
	map_size = get_arrsize(map);
	line_width = ft_strlen(*map);
	while (map[i])
	{
		if (i == 0 || i == map_size - 1)
			is_correct_wall_line(map[i]);
		else
			is_correct_middle_line(map[i]);
		if (ft_strlen(map[i]) != line_width)
			ft_exit_free(print_err(NOT_RECTANGULAR));
		i++;
	}
}
