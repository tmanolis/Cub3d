#include "cub3d.h"

int	print_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, 2);
	return (FAILURE);
}