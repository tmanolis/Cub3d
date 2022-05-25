#include "cub3d.h"

/*
	EN GROS : ici on envoie l'adresse de j et on fait les checks de map:
	PAS DE LIGNE VIDE pour espacer les lignes de map
	PAS DE CARACT non autorisé
	DOIT ETRE ENTOURE/FERME de 1
	à voir pour le reste

	ET
	des qu'on a une ligne vide : ciao on n'est plus dans la map

	ET : soit on le fait dans cette fonction, soit dans la main boucle mais 
	on doit checker qu'il n'y ait que des lignes vides / white spaces apres,
	si on a le moindre carac : ERROR map invalide
*/

/*
	ATTENTION : on va quand meme devoir stocker la map dans un char**
	Car comme dans son long on va devoir se deplacer dans ce tableau pour interragir
	et changer le render de la map quand on va bouger le joueur
*/

int	count_map_lines(t_data *data, char **map, int i)
{
	int index_value;
	int	j;

	index_value = i;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\r' // ETAPE 1 : IGNORER LES WHITESPACES
		|| map[i][j] == '\v' || map[i][j] == '\f')
			j++;
		if (map[i][j] != '1')
			break;
		i++;
	}
	data->map.index_end_of_map = i;
	return (i - index_value);
}

int	fill_map_array(t_map *map, char **map_array, int index)
{
	int i;

	i = 0;
	while (i < map->nb_line)
	{
		map_array[i] = strdup(map->map[index]);
		if (!map_array[i])
			return (FAILURE);
		i++;
		index++;
	}
	return (SUCCESS);
}

int	get_map_info(t_data *data, char **map, int i)
{
	data->map.nb_line = count_map_lines(data, map, i);
	data->map.map_array = (char **)malloc(sizeof(char *) * data->map.nb_line + 1);
	if (!data->map.map_array)
		return (FAILURE);
	if (fill_map_array(&data->map, data->map.map_array, i) == FAILURE)
		return (FAILURE);
}

int	parse_map_description(t_data *data, char **map, int i, int j)
{
	if (get_map_info(data, map, i) == FAILURE)
		return (FAILURE);
	for (int i = 0; data->map.map[i]; i++)
		printf("*: %s\n", data->map.map_array[i]);
	return (SUCCESS);
}

// Garder l'index_value de la ligne ou tu trouves la premiere ligne de la map
// comme si apres l'index value + fin de la map DU COUP PEUT ETRE GARDER l'index de la fin de map
// tu as autre chose que des /n, tu renvoies une erreur.