#include "so_long_bonus.h"

void	delete_item(t_conf *conf, t_coord next)
{
	t_list	**tmp;
	t_item	*node;

	tmp = &conf->item_list;
	while (*tmp)
	{
		node = (*tmp)->content;
		if (node->item_pos.x == next.x && node->item_pos.y == next.y)
		{
			ft_lstdelone(tmp, NULL);
			return ;
		}
		*tmp = (*tmp)->next;
	}
}

int	is_valid_position(t_conf *conf, t_coord next)
{
	int	out;

	out = ((next.x > 0 && next.x < (int)ft_strlen(*conf->map))
			&& (next.y > 0 && next.y < (int)get_arrsize(conf->map)));
	return (out);
}
