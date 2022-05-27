#include "cub3d.h"

/*
	EN GROS : ici on envoie l'adresse de j et on fait les checks de map:
	PAS DE LIGNE VIDE pour espacer les lignes de map
	à voir pour le reste
*/

int	is_a_white_space(char c)
{
	if (c != ' ' && c != '\t' && c != '\r'
		&& c != '\n' && c != '\v' && c != '\f')
		return (FAILURE);
	else
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
				return (print_error("There is an invalid letter in the map"));
			if (ft_strchr("NSEW", map_array[i][j]) && map->p_direction != '0')
				return (print_error("There is more than one player position"));
			if (ft_strchr("NSEW", map_array[i][j]) && map->p_direction == '0')
				map->p_direction = map_array[i][j];
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_top_or_bottom(char **map_array, int i, int j)
{
	while (map_array[i][j] == ' ' || map_array[i][j] == '\t' || map_array[i][j] == '\r'
	|| map_array[i][j] == '\v' || map_array[i][j] == '\f')
		j++;
	while (map_array[i][j])
	{
		if (map_array[i][j] != '1')
			return (FAILURE);
		j++;
	}
	return (SUCCESS);
}

int check_map_sides(t_map *map, char **map_array)
{
	int	i;
	int	j;

	if (check_top_or_bottom(map_array, 0, 0) == FAILURE)
		return (FAILURE);
	i = 1;
	while (i < (map->nb_line - 1))
	{
		j = ft_strlen(map_array[i]) - 1;
		if (map_array[i][j] != '1')
			return (FAILURE);
		i++;
	}
	if (check_top_or_bottom(map_array, i, 0) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

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

// int	check_left_side_is_closed(t_map *map, char **map_array)
// {
// 	int		i;
// 	int 	j;
	
// 	// check 2eme ligne
// 	(void) map;
// 	j = 0;
// 	while (map_array[1][j] && (is_a_white_space(map_array[1][j]) == SUCCESS || map_array[1][j] == '1'))
// 	{
// 		j++;
// 	}
// 	if (map_array[0][j] != '1')
// 		return (FAILURE);
// 	// check corps de map
// 	// 26/05 ADD MARINE : Attention, si on a "1N0 ..." avec les lignes environnantes ok cest ok
// 	i = 2;
// 	while (map_array[i] && ft_strchr(map_array[i], '0'))
// 	{
// 		j = 0;
// 		while (map_array[i][j] && (is_a_white_space(map_array[i][j]) == SUCCESS || ft_strchr("1NSEW", map_array[i][j])))
// 			j++;
// 		// printf("Valeur de j : %d. voici le char teste: %c\n", j, map_array[i][j]);
// 		if (is_a_white_space(map_array[i - 1][j]) == SUCCESS) // checker que l'on a pas un espace au dessus du 0
// 		{
// 			printf("1 Not closed. Line> |%s|, number %d\n", map_array[i - 1], i - 1);
// 			return (FAILURE);
// 		}	
// 		if (is_a_white_space(map_array[i + 1][j]) == SUCCESS) // checker que l'on a pas un espace en dessous du 0
// 		{
// 			printf("2 Not closed. Line> |%s|, number %d\n", map_array[i + 1], i + 1);
// 			return (FAILURE);
// 		}	
// 		if (map_array[i][j - 1] != '1' && !ft_strchr("NSEW", map_array[i][j - 1])) // checker que le 0 succède bien à un 1 ou une DIR
// 		{
// 			printf("3 J is : |%d| - Not closed. Line> |%s|, number %d\n", j, map_array[i], i);
// 			return (FAILURE);
// 		}	
// 		i++;
// 	}
// 	return (SUCCESS);
// }

int	check_left_side_is_closed(char **map_array)
{
	int		i;
	int 	j;
	
	j = 0;
	while (map_array[1][j] && (is_a_white_space(map_array[1][j]) == SUCCESS
		|| map_array[1][j] == '1'))
		j++;
	if (map_array[0][j] != '1')
		return (FAILURE);
	i = 2;
	while (map_array[i] && ft_strchr(map_array[i], '0'))
	{
		j = 0;
		while (map_array[i][j] && (is_a_white_space(map_array[i][j]) == SUCCESS
			|| ft_strchr("1NSEW", map_array[i][j])))
			j++;
		if (is_a_white_space(map_array[i - 1][j]) == SUCCESS)
			return (FAILURE);
		if (is_a_white_space(map_array[i + 1][j]) == SUCCESS)
			return (FAILURE);
		if (!ft_strchr("1NSEW", map_array[i][j - 1]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_map_retrieved(t_map *map, char **map_array)
{
	// RAJOUTER UN CHECK GENRE MAP DE MIN 3 Lignes par ex ?if (
	if (check_letters(map, map_array) == FAILURE)
		return (FAILURE);
	if (map->p_direction == '0')
		return (print_error("The map should have a player position"));
	if (check_map_sides(map, map_array) == FAILURE)
		return (print_error("The map must be surrounded by walls"));
	if (check_left_side_is_closed(map_array) == FAILURE)
		return (print_error("The map is not fully closed"));
	if (check_map_is_at_the_end(map) == FAILURE)
		return (print_error("The map description is not the last element"));
	
	return (SUCCESS);
}
