#include "cub3d.h"

void	mlx_loop_and_hooks(t_data data)
{
	// mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, ClientMessage, LeaveWindowMask, &handle_crossbtn, &data);
	mlx_loop(data.mlx);
}

