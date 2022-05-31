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
}