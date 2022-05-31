#include "cub3d.h"

void	free_double_array(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

void	free_graphics(t_graphics *graphics)
{
	
}

void	free_map(t_map *map)
{
	if (fd != 0)
}

void	free_for_your_life(t_data *data)
{
	free_graphics(&data->graphics);
	free_map(&data->map)
}