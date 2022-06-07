#include "cub3d.h"

/*
	"We need to retrieve a pixel at some x and y coordinates, 
	but we're dealing with a one dimensional array.
	The formula to get the right index  is : index = line_len * y + x * (bpp / 8)"
	
	=> We're creating our own mlx_pixel_put because "the mlx_pixel_put function 
	basically draws the pixel on the window directly, without waiting for the 
	whole background to be drawn = ugly flickering on the screen"
*/

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

// dessine les cubes collés les un aux autres
void	draw_a_cell(t_data *data, int beginX, int beginY, int lenX, int lenY, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < lenX)
	{
		j = 0;
		while (j < lenY)
		{
			my_mlx_pixel_put(&data->img, beginX + i, beginY + j, color);
			j++;
		}
		i++;
	}
}

// avec les i et j set à 1, on a un petit espace esthetique entre chaque cube
void	draw_a_cell2(t_data *data, int beginX, int beginY, int lenX, int lenY, int color)
{
	int	i;
	int	j;

	i = 1;
	while (i < lenX)
	{
		j = 1;
		while (j < lenY)
		{
			my_mlx_pixel_put(&data->img, beginX + i, beginY + j, color);
			j++;
		}
		i++;
	}
}


void	draw_player_pos(t_data *data)
{
	draw_a_cell(data, data->map.p_x * 8, data->map.p_y * 8, 8, 8, PINK);
}

void	draw_the_2d_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < 24) // 24 est la hauteur de la map
	{
		j = 0;
		while (j < 24) // width de la map
		{
			if (data->map.map[i][j] == '1') // si c'est un mur
			{
				draw_a_cell(data, j * 8, i * 8, 8, 8, WHITE);
			}
			else
				draw_a_cell2(data, j * 8, i * 8, 8, 8, PURPLE);
			j++;
		}
		i++;
	}
	draw_player_pos(data);
}

