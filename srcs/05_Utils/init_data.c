#include "cub3d.h"

void	init_graphics(t_graphics *graphics)
{
	graphics->dir_NO = NULL;
	graphics->dir_SO = NULL;
	graphics->dir_WE = NULL;
	graphics->dir_EA = NULL;
	graphics->floor = 0;
	graphics->ceiling = 0;
}

void	init_data(t_data *data)
{
	init_graphics(&data->graphics);
	// init_map
	data->win_height = 800;
	data->win_width = 1500;
	
	
}

// data->win_height = data->map.line_count * IMG_SIZE;
// data->win_width = (ft_strlen(data->map.map[0]) - 1) * IMG_SIZE;

