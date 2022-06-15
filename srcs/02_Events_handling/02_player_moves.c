# include "cub3d.h"

int	key_press(t_data *data, int keysym)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = data->map.dir_x;
	old_plane_x = data->map.plane_x;
	if (keysym = 'w')
	{
		if (!data->map.map[(int)(data->map.p_x + data->map.dir_x * data->map.move_speed)][data->map.p_y])
			data->map.p_x += data->map.dir_x * data->map.move_speed;
		if (!data->map.map[(int)(data->map.p_x)][(int)(data->map.p_y + data->map.dir_y * data->map.move_speed)])
			data->map.p_y += data->map.dir_y * data->map.move_speed;
	}
	//move backwards if no wall behind you
	if (keysym = 's')
	{
		if (!data->map.map[(int)(data->map.p_x - data->map.dir_x * data->map.move_speed)][(int)(data->map.p_y)])
			data->map.p_x -= data->map.dir_x * data->map.move_speed;
		if (!data->map.map[(int)(data->map.p_x)][(int)(data->map.p_y - data->map.dir_y * data->map.move_speed)])
			data->map.p_y -= data->map.dir_y * data->map.move_speed;
	}
	//rotate to the right
	if (keysym = 'd')
	{
		//both camera direction and camera plane must be rotated
		data->map.dir_x = data->map.dir_x * cos(-data->map.rotate_speed) - data->map.dir_y * sin(-data->map.rotate_speed);
		data->map.dir_y = old_dir_x * sin(-data->map.rotate_speed) + data->map.dir_y * cos(-data->map.rotate_speed);
		data->map.plane_x = data->map.plane_x * cos(-data->map.rotate_speed) - data->map.plane_y * sin(-data->map.rotate_speed);
		data->map.plane_y = old_plane_x * sin(-data->map.rotate_speed) + data->map.plane_y * cos(-data->map.rotate_speed);
	}
	//rotate to the left
	if (keysym = 'a')
	{
		//both camera direction and camera plane must be rotated
		data->map.dir_x = data->map.dir_x * cos(data->map.rotate_speed) - data->map.dir_y * sin(data->map.rotate_speed);
		data->map.dir_y = old_dir_x * sin(data->map.rotate_speed) + data->map.dir_y * cos(data->map.rotate_speed);
		data->map.plane_x = data->map.plane_x * cos(data->map.rotate_speed) - data->map.plane_y * sin(data->map.rotate_speed);
		data->map.plane_y = old_plane_x * sin(data->map.rotate_speed) + data->map.plane_y * cos(data->map.rotate_speed);
	}
	return (0);
}