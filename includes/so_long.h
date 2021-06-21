#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "mlx.h"
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
void	get_items_pos(t_conf *conf);
void	get_player_pos(char **map, t_coord *player_pos);

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
int		open_file(char *path);
char	**lst_to_arr(t_list *lst);
t_tex	*choose_texture(t_conf *conf, char c);

/*
** FILE - hooks.c
*/
int		exit_game(t_conf *vars);
int		focus_window(t_conf *vars);
int		keypress(int keycode, t_conf *vars);
int		keyrelease(int keycode, t_conf *vars);
int		loop_hook(t_conf *v);

/*
** FILE - window.c
*/
void	init_window(t_conf *conf);

/*
** FILE - window_utils.c
*/
void	get_screen_size(void *mlx, int *x, int *y);

/*
** FILE - draw_utils.c
*/
void	ft_draw_img(t_conf *conf, int x, int y);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	draw_cube(t_conf *conf, int startx, int starty);

/*
** FILE - cube_utils.c
*/
int		get_cube_size(t_coord res, char **map);

/*
** FILE - move_player.c
*/
void	move_north(t_conf *conf);
void	move_south(t_conf *conf);
void	move_east(t_conf *conf);
void	move_west(t_conf *conf);

#endif
