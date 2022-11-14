/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_check_info_retrieved.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:19:32 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/04 08:48:44 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_input_of_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			ft_putstr_fd("Error\nThe following number is invalid : ", 2);
			ft_putnbr_fd(rgb[i], 2);
			ft_putchar_fd('\n', 2);
			ft_putstr_fd("RGB has a min val of 0 and a max value of 255.\n", 2);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static int	check_existence_of_path(char *path)
{
	int	fd;
	int	len;

	fd = open(path, O_RDWR);
	len = ft_strlen(path);
	if ((path[len - 4] != '.' || path[len - 3] != 'x' || path[len - 2] != 'p'
			|| path[len - 1] != 'm'))
	{
		close(fd);
		return (FAILURE);
	}
	if (fd == -1)
	{
		close(fd);
		ft_putstr_fd("Error\nThe following path is invalid : ", 2);
		ft_putstr_fd(path, 2);
		ft_putchar_fd('\n', 2);
		return (FAILURE);
	}
	return (SUCCESS);
}

unsigned long	convert_rgb_to_hex(int *rgb_array)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_array[0];
	g = rgb_array[1];
	b = rgb_array[2];
	result = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (result);
}

int	check_info_retrieved(t_graphics *graphics)
{
	if (!graphics->dir_no || !graphics->dir_so || !graphics->dir_we
		|| !graphics->dir_ea || !graphics->floor || !graphics->ceiling)
		return (FAILURE);
	if (check_existence_of_path(graphics->dir_no) == FAILURE
		|| check_existence_of_path(graphics->dir_so) == FAILURE
		|| check_existence_of_path(graphics->dir_we) == FAILURE
		|| check_existence_of_path(graphics->dir_ea) == FAILURE
		|| check_input_of_rgb(graphics->floor) == FAILURE
		|| check_input_of_rgb(graphics->ceiling) == FAILURE)
		return (FAILURE);
	graphics->hex_floor = convert_rgb_to_hex(graphics->floor);
	graphics->hex_ceiling = convert_rgb_to_hex(graphics->ceiling);
	return (SUCCESS);
}
