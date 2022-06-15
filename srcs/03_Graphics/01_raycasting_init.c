#include "cub3d.h"

/*
	posX, posY => position of player
	dirX, dir Y => direction of player
	planeX, planeY => camera plane of player

	Ratio entre longueur de la direction et camera plane = FOV (field of view)
	On va mettre le FOV à 60 environ


*/

/**
 * @brief 
 * 
 * @param data 
 * @return int 
 */
static int	init_textures(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			data->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	data->textures = (int **)malloc(sizeof(int *) * 8);
	if (!data->textures)
		return ;
	i = 0;
	while (i < 8)
	{
		data->textures[i] = (int *)malloc(sizeof(int) * (T_HEIGHT * T_WIDTH));
		if (!data->textures[i])
			return ;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < T_HEIGHT * T_WIDTH)
		{
			data->textures[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	load_img_buffer(t_data *data, int *texture, char *path, t_buf *buf)
{
	int	y;
	int	x;

	buf->img = mlx_xpm_file_to_image(data->mlx, path, &buf->img_width, &buf->img_height);
	buf->info = (int *)mlx_get_data_addr(buf->img, &buf->bpp, &buf->size_l, &buf->endian);
	y = 0;
	while (y < buf->img_height)
	{
		x = 0;
		while (x < buf->img_width)
		{
			texture[buf->img_width * y + x] = buf->info[buf->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, buf->img);
}

static void	load_texture(t_data *data)
{
	t_buf	img;

	load_img_buffer(data, data->textures[0], "textures/eagle.xpm", &img);
	load_img_buffer(data, data->textures[1], "textures/redbrick.xpm", &img);
	load_img_buffer(data, data->textures[2], "textures/purplestone.xpm", &img);
	load_img_buffer(data, data->textures[3], "textures/greystone.xpm", &img);
	load_img_buffer(data, data->textures[4], "textures/bluestone.xpm", &img);
}

void	init_raycasting(t_data *data)
{
	// ce qui suit c'est pour que la minimap marche
	// data->map.dir_x = -1;
	// data->map.dir_y = 1;
	// data->map.plane_x = 0;
	// data->map.plane_y = 0.66;
	// data->map.move_speed = 1; // test, valeur arbitraire
	// data->map.rotate_speed = 1;

	// pour que le raycasting et moves marchent
	data->map.dir_x = -1;
	data->map.dir_y = 0;
	data->map.plane_x = 0.0;
	data->map.plane_y = 0.66;
	data->map.move_speed = 0.05;
	data->map.rotate_speed = 0.05;

	init_textures(data);
	load_textures(data);
}