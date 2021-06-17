#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_coord {
	int	x;
	int	y;
}	t_coord;

typedef struct s_item {
	t_coord	item_pos;
	int		state;
}	t_item;

typedef struct s_conf {
	char	**map;
	t_coord	*player_pos;
	t_list	*item_list;
}	t_conf;

#endif
