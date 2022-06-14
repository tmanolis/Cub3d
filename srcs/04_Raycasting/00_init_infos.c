#include "cub3d.h"

int		**convert_map_char_into_int(t_data *data, char **map_char)
{
	int	i;
	int	j;
	int	**map_int;

	map_int = (int **)malloc(sizeof(int *) * data->map.nb_line);
	if (!map_int)
		return (NULL);
	i = 0;
	while (map_char[i])
	{
		j = 0;
		map_int[i] = (int *)malloc(sizeof(int) * ft_strlen(map_char[i]));
		while (map_char[i][j])
		{
			map_int[i][j] = map_char[i][j] - 48;
			if (map_int[i][j] >= 17 && map_int[i][j] <= 42)
				map_int[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map_int);
}

void	print_map_int(t_data *data, int **map)
{
	int i;
	size_t j;

	i = 0;
	while (i < data->map.nb_line)
	{
		j = 0;
		while (j < ft_strlen(data->map.map[i]))
		{
			// printf("%d", map[i][j]);
			ft_putnbr_fd(map[i][j], 1);
			j++;
		}
		i++;
		write(1, "\n", 1);
	}
	printf("j'ai bien print la map\n");
}

void	init_infos(t_data *data, t_infos *infos)
{
	// (void)data;

	infos->posX = (double)data->map.p_x;
	infos->posY = (double)data->map.p_y;
	infos->map = convert_map_char_into_int(data, data->map.map);
	// print_map_int(data, infos->map);
	// infos->posX = 12;
	// infos->posY = 5;
	infos->dirX = -1;
	infos->dirY = 0;
	infos->planeX = 0;
	infos->planeY = 0.66;
	infos->moveSpeed = 0.05;
	infos->rotSpeed = 0.05;
}