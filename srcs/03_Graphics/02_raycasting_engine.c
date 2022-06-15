#include "cub3d.h"

int	worldMap[24][24] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
							{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						};

void	verLine(t_data *data, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, color);
		y++;
	}
}

void	calc(t_data *data)
{
	t_map	*map;
	int	x;

	map = &data->map;
	x = 0;
	while (x < data->win_width)
	{
		double cameraX = 2 * x / (double)data->win_width - 1;
		double rayDirX = map->dir_x + map->plane_x * cameraX;
		double rayDirY = map->dir_y + map->plane_y * cameraX;
		
		int mapX = (int)map->pos_x;
		int mapY = (int)map->pos_y;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		
		 //length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;
		
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (map->pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - map->pos_x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (map->pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - map->pos_y) * deltaDistY;
		}

		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			
			if (map->map[mapX][mapY] == '1') 
				hit = 1;
			// else if (map->map[mapX][mapY] == 2)
			// {
			// 	printf("boucle hit : %d\n", map->map[mapX][mapY]);
			// 	hit = 1;
			// }
		}
		if (side == 0)
			perpWallDist = (mapX - map->pos_x + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - map->pos_y + (1 - stepY) / 2) / rayDirY;

		//Calculate height of line to draw on screen
		int lineHeight = (int)(data->win_height / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + data->win_height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + data->win_height / 2;
		if(drawEnd >= data->win_height)
			drawEnd = data->win_height - 1;

		int	color;
		// printf("je tombe sur cette valeur : %c\n", map->map[mapX][mapY]);
		if (map->map[mapX][mapY] == '1')
			color = PINK; // rouge
		// else if (map->map[mapX][mapY] == '2')
		// 	color = 0x00FF00;  // vert
		// else if (map->map[mapX][mapY] == 3)
		// 	color = 0x0000FF; // bleu
		// else if (map->map[mapX][mapY] == 4)
		// 	color = 0xFFFFFF; // white
		// else if (map->map[mapX][mapY] == 5)
		// 	color = 0xFFFF00; // jaune
		else
			color = PURPLE;
		if (side == 1)
			color = color / 2;

		verLine(data, x, drawStart, drawEnd, color);
		
		x++;
	}
}

int	raycasting_loop(t_data *data)
{
	calc(data);
	// mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);

	return (0);
}