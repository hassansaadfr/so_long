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

void	print_err(char *msg);

/*
** FILE - parser.c
*/

char	**parse(char *path);

/*
** FILE - engine.c
*/

void	game(t_conf *conf);

#endif
