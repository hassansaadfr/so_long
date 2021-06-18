#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"
# include "constant.h"
# include "struct.h"

/*
** FILE - error.c
*/

int		print_err(char *msg);

/*
** FILE - parser.c
*/

char	**parse(char *path);

/*
** FILE - parser_utils.c
*/
void	is_correct_map(char **map);

/*
** FILE - engine.c
*/
void	game(t_conf *conf);

/*
** FILE - utils.c
*/
size_t	get_arrsize(char **arr);

#endif
