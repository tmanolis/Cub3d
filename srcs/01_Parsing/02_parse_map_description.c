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

int	parse_map_description(t_data *data, t_graphics *graph, char *line, int j)
{

}