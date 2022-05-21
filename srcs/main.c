#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_arg(argv[1]) == FAILURE)
			return (write(STDERR_FILENO, "Is not an existing .ber file\n", 30));
	}
	else
		ft_putstr_fd("Correct usage is ./cub3d <map.cub>\n", STDERR_FILENO);
	return (0);
}