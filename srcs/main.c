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
	}
	else
		ft_putstr_fd(MSG_WRONG_NB_ARG, STDERR_FILENO);
	return (0);
}