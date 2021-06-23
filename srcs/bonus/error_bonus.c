#include "so_long_bonus.h"

int	print_err(char *msg)
{
	ft_putendl_fd("Error.", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
	return (1);
}
