#include "cub3d.h"

void	init_infos(t_data *data, t_infos *infos)
{
	// (void)data;
	infos->posX = (double)data->map.p_x;
	infos->posY = (double)data->map.p_y;
	// infos->posX = 12;
	// infos->posY = 5;
	infos->dirX = -1;
	infos->dirY = 0;
	infos->planeX = 0;
	infos->planeY = 0.66;
	infos->moveSpeed = 0.05;
	infos->rotSpeed = 0.05;
}