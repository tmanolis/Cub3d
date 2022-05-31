#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../includes/get_next_line.h"
# include "../includes/structs.h"

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define MSG_WRONG_FILE "Error.\nIs not an existing .cub file\n"
# define MSG_MISSING_INFO "Error.\nThe .cub file is missing some info.\n"
# define MSG_INVALID_INFO "Error.\nThe infos of this map are invalid.\n"
# define MSG_WRONG_NB_ARG "Correct usage is ./cub3d <map.cub>\n"

enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERR = 2,
	BREAK = 3,
	CONTINUE = 4
};

// 00_ERR_HANDLING - 00_check_arg.c
int		check_arg(char *arg);

// 01_PARSING - 00_open_file.c
void	create_map_from_cub_file(char *path, t_data *data);
// 01_PARSING - 01_retrieve_info_in_file.c
int		retrieve_info_in_file(t_data *data, char **map);
// 01_PARSING - 02_parse_map_description.c
int		retrieve_map_description(t_data *data, char **map, int i);
// 01_PARSING - 03_check_info_retrieved.c
int		check_info_retrieved(t_graphics *graphics);
// 01_PARSING - 04_check_map_retrieved.c
int		check_map_retrieved(t_map *map, char **map_array);
// 01_PARSING - 05_check_map_borders.c
int		check_top_or_bottom(char **map_array, int i, int j);
int		check_map_sides(t_map *map, char **map_array);
int		check_left_side_is_closed(char **map_array);
int		check_right_side_is_closed(char **map_array);

// 05_UTILS - free_double_array.c
void	free_double_array(char **tab);
// 05_UTILS - init_data.c
void	init_data(t_data *data);
// 05_UTILS - utils_functions.c
int		is_a_white_space(char c);
int		print_error(char *str);


#endif