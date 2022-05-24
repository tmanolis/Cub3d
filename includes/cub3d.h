#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../includes/get_next_line.h"

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERROR = 2,
};

enum e_map_errors
{
	INCORRECT_MAP = 3,
	INFO_ALREADY_FILLED,
	WRONG_INPUT
};

typedef struct	s_graphics
{
	char	*dir_NO;
	char	*dir_SO;
	char	*dir_WE;
	char	*dir_EA;
	int		*floor;
	int		*ceiling;
}				t_graphics;

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	char	*path;
	char	**map;
	int		nb_line;
	char	**map_array;
	int		index_end_of_map;
}				t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_graphics	graphics;
	t_map		map;

}				t_data;

// 00_ERROR_HANDLING - 00_check_arg.c
int		check_arg(char *arg);

// 01_PARSING - 00_open_file.c
void	create_map_from_cub_file(char *path, t_data *data);
int		retrieve_info_in_file(t_data *data, t_graphics *graphics, char **map);
// 01_PARSING - 02_parse_map_description.c
int		parse_map_description(t_data *data, char **map, int i, int j);

// 05_UTILS - free_double_array.c
void	free_double_array(char **tab);
// 05_UTILS - init_data.c
void	init_data(t_data *data);


#endif