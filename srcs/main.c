#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		if (check_arg(argv[1]) == FAILURE)
			return (write(STDERR_FILENO, "Is not an existing .ber file\n", 30));
		create_map_from_cub_file(argv[1], &data);
		for (int i = 0; data.map.map[i]; i++)
			printf("*: %s\n", data.map.map[i]);
	}
	else
		ft_putstr_fd("Correct usage is ./cub3d <map.cub>\n", STDERR_FILENO);
	return (0);
}