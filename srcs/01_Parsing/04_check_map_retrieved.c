#include "cub3d.h"

int	check_map_is_at_the_end(t_map *map)
{
	int	i;
	int j;

	i = map->index_end_of_map;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != ' ' && map->file[i][j] != '\t' && map->file[i][j] != '\r'
			&& map->file[i][j] != '\n' && map->file[i][j] != '\v' && map->file[i][j] != '\f')
				return (FAILURE);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_map_retrieved(t_map *map, char **map_array)
{
	(void)map_array;
	if (check_map_is_at_the_end(map) == FAILURE)
	{
		ft_putstr_fd("The map description is not the last element\n", 2);
		return (FAILURE);
	}
	return (SUCCESS);
}