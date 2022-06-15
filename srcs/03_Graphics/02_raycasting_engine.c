#include "cub3d.h"

void	draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			data->buf.info[y * W_WIDTH + x] = data->buffer[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->buf.img, 0, 0);
}

void	calc(t_data *data)
{
	int	x;

	x = 0;
	while (x < W_WIDTH)
	{
		//calculate ray position and direction
		double camera_x = 2 * x / (double)W_WIDTH - 1; // x-coordinate in camera space
		double ray_dir_x = data->map.dir_x + data->map.plane_x * camera_x;
		double ray_dir_y = data->map.dir_y + data->map.plane_y * camera_x;
		
		 //which box of the map we're in
		int mapX = data->map.p_x;
		int mapY = data->map.p_y;

		//length of ray from current position to next x or y-side
		double side_dist_x;
		double side_dist_y;
		
		 //length of ray from one x or y-side to next x or y-side
		double delta_dist_x = fabs(1 / ray_dir_x); // fabs returns the absolute value of the arg.
		double delta_dist_y = fabs(1 / ray_dir_y);
		double perp_wall_dist; // aka perpendicular wall distance
		
		//what direction to step in x or y-direction (either +1 or -1)
		int step_x;
		int step_y;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = ((double)data->map.p_x - mapX) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (mapX + 1.0 - (double)data->map.p_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = ((double)data->map.p_y - mapY) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (mapY + 1.0 - (double)data->map.p_y) * delta_dist_y;
		}

		 //perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				mapX += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				mapY += step_y;
				side = 1;
			}
			 //Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}
		//Calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
		if (side == 0)
			perp_wall_dist = (mapX - (double)data->map.p_x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (mapY - (double)data->map.p_y + (1 - step_y) / 2) / ray_dir_y;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(height / perp_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + height / 2;
		if(drawEnd >= height)
			drawEnd = height - 1;

		// texturing calculations
		int texNum = worldMap[mapX][mapY];

		// calculate value of wallX
		double wallX;
		if (side == 0)
			wallX = (double)data->map.p_y + perp_wall_dist * ray_dir_y;
		else
			wallX = (double)data->map.p_x + perp_wall_dist * ray_dir_x;
		wallX -= floor(wallX);

		// x coordinate on the texture
		int texX = (int)(wallX * (double)texWidth);
		if (side == 0 && ray_dir_x > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && ray_dir_y < 0)
			texX = texWidth - texX - 1;

		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHeight / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - height / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y < drawEnd; y++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = info->texture[texNum][texHeight * texY + texX];
			// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
			if (side == 1)
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
		}
		x++;
	}
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}
