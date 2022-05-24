#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;
	t_graphics graphics;

	if (argc == 2)
	{
		if (check_arg(argv[1]) == FAILURE)
			return (write(STDERR_FILENO, "Is not an existing .cub file\n", 30));
		create_map_from_cub_file(argv[1], &data);
		// for (int i = 0; data.map.map[i]; i++)
			// printf("*: %s\n", data.map.map[i]);
		graphics.dir_NO = NULL;
		graphics.dir_SO = NULL;
		graphics.dir_WE = NULL;
		graphics.dir_EA = NULL;
		graphics.floor = 0;
		graphics.ceiling = 0;
		if (retrieve_info_in_file(&data, &graphics, data.map.map) == FAILURE)
			return (write(2, "Error : does not comply w the rules of the map\n", 63));
	}
	else
		ft_putstr_fd("Correct usage is ./cub3d <map.cub>\n", STDERR_FILENO);
	return (0);
}