#include "cub3d.h"

// Ex : EA         ./path_to_the_east_texture   test
/**
 * @brief Get the path of texture object
 * 			Steps:
 * 			1) If there are any spaces or tabs, just ignore them 
 * 			2) Count in advance the total length of the path for the malloc
 * 			3) Copy the path into the newly malloced var until you encounter a space/tab
 * 			4) Check if there are any alphanum chars (even dots or slashes) after => should it be the case, return NULL
 * 			5) return the path
 * 
 * @param line 
 * @param j 
 * @return char* 
 */
static char	*get_path_of_texture(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' '  && line[len] != '\t'))
		len++;
	path = (char *)malloc(sizeof(char) * (len - j + 1)); // combine pour la norme (em gros dans le compteur precedent len ne demarre pas à 0 mais à j,il faut donc l'enlever)
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

// Ex: "  C        225,30,0"
static int	*get_rgb_colors(char *line) // normalement on a envoyé line + j + 1
{
	char	**rgb_to_convert;
	int		*rgb;
	int		i;

	rgb_to_convert = ft_split(line, ','); 
	// nb : on s'en fout s'il y a des espaces dans les elts splittés vu que le atoi les ignore
	// TODO CHECKER AVEC ESPACES APRES LE NB
	rgb = (int *)malloc(sizeof(int) * 3);
	if (!rgb)
		return (0);
	i = 0;
	while (rgb_to_convert[i])
	{
		if (i > 2) // cas où qqun fait le test : "C        225,30,0,5,20"
			return (0);
		rgb[i] = ft_atoi(rgb_to_convert[i]);
		i++;
	}
	return (rgb);
}

/**
 * @brief 
 * 
 * @param graph 
 * @param line 
 * @param j 
 * @return int 
 */
static int	fill_in_the_correct_dir(t_graphics *graph, char *line, int j)
{
	if (line[j + 2] && ft_isprint(line[j + 2])) // cas où la ligne c'est : SOU ./path_to_the_south_texture
		return (WRONG_INPUT);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(graph->dir_NO))
		graph->dir_NO = get_path_of_texture(line, j + 2); // j + 2 pour passer les deux lettres de la dir
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(graph->dir_SO))
		graph->dir_SO = get_path_of_texture(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(graph->dir_WE))
		graph->dir_WE = get_path_of_texture(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(graph->dir_EA))
		graph->dir_EA = get_path_of_texture(line, j + 2);
	else
		return (WRONG_INPUT);
	return (SUCCESS);
}

static int fill_in_the_floor_or_ceiling(t_graphics *graph, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1])) // cas où la ligne c'est : FLOOR 220,100,0 au lieu de F 220,100,0
		return (WRONG_INPUT);
	if (!graph->ceiling && line[j] == 'C')
		graph->ceiling = get_rgb_colors(line + j + 1);
	else if (!graph->floor && line[j] == 'F')
		graph->floor = get_rgb_colors(line + j + 1);
	else
		return (WRONG_INPUT);
	return (SUCCESS);
}

int	retrieve_info_in_file(t_data *data, t_graphics *graphics, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		// printf("%s\n", map[i]);
		while (map[i][j])
		{
			while (map[i][j] == ' ' || map[i][j] == '\t' || map[i][j] == '\r' // ETAPE 1 : IGNORER LES WHITESPACES
			|| map[i][j] == '\n' || map[i][j] == '\v' || map[i][j] == '\f')
				j++;
			// printf("laligne ap les whitespaces: %s\n", map[i] + j);
			if (ft_isalpha(map[i][j])) // ETAPE 2 : on check s'il y a des chars dans cette ligne, et si oui, s'il y en a 1 ou 2
			{
				// printf("voici le char traité : %c\n", map[i][j]);
				if (map[i][j + 1] && ft_isalpha(map[i][j + 1]))
				{
					if (fill_in_the_correct_dir(graphics, map[i], j) == WRONG_INPUT)
						return (FAILURE);
					break ; // en gros, dès que la ligne est traitée, il faut passer à la ligne d'en dessous (i++)
				}	
				else
				{
					if (fill_in_the_floor_or_ceiling(graphics, map[i], j) == WRONG_INPUT)
						return (FAILURE);
					break ;
				}	
			}
			else if (ft_isdigit(map[i][j]))
			{
				if (parse_map_description(data, map, i, j) == INCORRECT_MAP) //c'est la qu'on envoie l'adresse du j
					return (FAILURE); 
			}
			j++;
		}
		i++;
	}
	printf("VOICI LES DONNEES RECUP :\nDirections: NO : %s | SO : %s | WE : %s | EA : %s\n", graphics->dir_NO, graphics->dir_SO, graphics->dir_WE, graphics->dir_EA);
	if (graphics->floor)
	{
		for (int k = 0; graphics->floor[k]; k++)
			printf("floor: %d => %d\n", k, graphics->floor[k]);
	}
	if (graphics->ceiling)
	{
		for (int l = 0; graphics->ceiling[l]; l++) // PB avec le 0, qui est genre la "fin" du int * et du coup s'imprime pas
			printf("ceiling: %d => %d\n", l, graphics->ceiling[l]);
	}
	if (!graphics->dir_NO || !graphics->dir_SO || !graphics->dir_WE 
		|| !graphics->dir_EA || !graphics->floor || !graphics->ceiling)
		return (FAILURE);
	printf("tout est bon!\n");
	return (SUCCESS);
}


// ITERE DANS CHAR **MAP
/*
	STR[I]
	{
		on ignore les whitespaces
		IF On checke les premiers caract :
		si y a deux chars : WE NO SO EA /!\ et que la var correspondante n'a pas deja ete remplie
			Et ca doit etre suivi d'un path (une string sans espaces)
			
			par ex split sur les espaces et on veut un tab de taille 2
		si y a qu'un char : F C


		IF {
			isdigit ? OUI => on the map = true
			{
				on envoie l'adresse de j
				parse_map_description : 
			}
			ligne vide  => ALARM break ERROR
		}
		if (!dir || !dir || !floor | !ceiling)
		ERROR
	}
*/