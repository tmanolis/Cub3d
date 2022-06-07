#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc == 2)
	{
		init_data(&data);
		if (check_arg(argv[1]) == FAILURE)
			return (print_error(MSG_WRONG_FILE));
		create_map_from_cub_file(argv[1], &data);
		if (retrieve_info_in_file(&data, data.map.file) == FAILURE)
			return (free_for_your_life(&data));
		if (check_info_retrieved(&data.graphics) == FAILURE)
			return (print_error(MSG_INVALID_INFO) && free_for_your_life(&data));
		check_map_retrieved(&data.map, data.map.map);
		init_window(&data);	
		mlx_loop_and_hooks(data);
		mlx_loop(data.mlx);
		// mlx_destroy_display(data.mlx);
		free_for_your_life(&data);
	}
	else
		ft_putstr_fd(MSG_WRONG_NB_ARG, STDERR_FILENO);
	return (0);
}