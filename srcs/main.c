#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		init_data(&data);
		if (check_arg(argv[1]) == FAILURE)
			return (write(STDERR_FILENO, "Is not an existing .cub file\n", 30));
		create_map_from_cub_file(argv[1], &data);
		if (retrieve_info_in_file(&data, data.map.file) == FAILURE)
			return (write(2, "Error : does not comply w the rules of the map\n", 63));
	
		if (check_info_retrieved(&data.graphics) == FAILURE)
			return (write(2, "Error.\nThe infos of this map are invalid.\n", 43));
	}
	else
		ft_putstr_fd("Correct usage is ./cub3d <map.cub>\n", STDERR_FILENO);
	return (0);
}