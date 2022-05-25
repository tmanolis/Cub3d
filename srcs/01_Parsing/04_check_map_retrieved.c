#include "cub3d.h"

/*
	EN GROS : ici on envoie l'adresse de j et on fait les checks de map:
	PAS DE LIGNE VIDE pour espacer les lignes de map
	DOIT ETRE ENTOURE/FERME de 1
	à voir pour le reste
*/

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

int	check_letters(t_map *map, char **map_array)
{
	int	i;
	int	j;

	i = 0;
	map->p_direction = '0';
	while (map_array[i])
	{
		j = 0;
		while (map_array[i][j])
		{
			while (map->map[i][j] == ' ' || map->map[i][j] == '\t' || map->map[i][j] == '\r'
			|| map->map[i][j] == '\v' || map->map[i][j] == '\f')
				j++;
			if (!(ft_strchr("10NSEW", map_array[i][j])))
				return (print_error("There is an unvalid letter in the map\n"));
			if (ft_strchr("NSEW", map_array[i][j]) && map->p_direction != '0')
				return (print_error("There is more than one player position\n"));
			if (ft_strchr("NSEW", map_array[i][j]) && map->p_direction == '0')
				map->p_direction = map_array[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_map_retrieved(t_map *map, char **map_array)
{
	if (check_letters(map, map_array) == FAILURE)
		return (FAILURE);
	if (check_map_is_at_the_end(map) == FAILURE)
		return (print_error("The map description is not the last element\n"));
	return (SUCCESS);
}