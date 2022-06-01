#include "cub3d.h"

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (FAILURE);
	data->win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, TITLE);
	if (data->win == NULL)
	{
		free(data->win);
		return (FAILURE);
	}
	return (SUCCESS);
}