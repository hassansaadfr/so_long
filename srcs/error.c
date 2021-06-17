#include "so_long.h"

void	print_err(char *msg)
{
	ft_putendl_fd("Error.", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
}
