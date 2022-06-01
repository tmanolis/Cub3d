#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		init_data(&data);
		if (check_arg(argv[1]) == FAILURE)
			return (write(STDERR_FILENO, MSG_WRONG_FILE, 37));
		create_map_from_cub_file(argv[1], &data);
		if (retrieve_info_in_file(&data, data.map.file) == FAILURE)
			return (write(STDERR_FILENO, MSG_MISSING_INFO, 44));
	
		if (check_info_retrieved(&data.graphics) == FAILURE)
			return (write(STDERR_FILENO, MSG_INVALID_INFO, 43));
		
		check_map_retrieved(&data.map, data.map.map);
		// if (check_info_retrieved(&data.graphics) == FAILURE || check_map_retrieved(&data.map, data.map.map) == FAILURE)
		// 	return (write(2, "Error.\nThe infos of this map are invalid.\n", 43));
		init_window(&data);
		printf("Window lancée, z'est partiiiiii!\n");
		mlx_loop_and_hooks(&data);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		printf("Fin de la simulation\n");
		return (0);
	}
	else
		ft_putstr_fd(MSG_WRONG_NB_ARG, STDERR_FILENO);
	return (0);
}