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
	ERROR = 2
};

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	char	*path;
	char	**map;
}				t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_width;
	t_map	map;

}				t_data;

// 00_ERROR_HANDLING - 00_check_arg.c
int		check_arg(char *arg);

// 01_PARSING - 00_open_file.c
void	create_map_from_cub_file(char *path, t_data *data);

// 05_UTILS - free_double_array.c
void	ft_free(char **tab);

#endif