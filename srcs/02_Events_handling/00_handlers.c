#include "cub3d.h"

int	handle_crossbtn(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	// else if (ft_strchr("wasd", keysym))
	// 	move_player(data, keysym);
	return (0);
}