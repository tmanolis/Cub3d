#ifndef STRUCTS_H
# define STRUCTS_H

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
	char	*path;
	char	**file;
	int		nb_line;
	char	**map;
	int		index_end_of_map;
	char	p_direction;
	int		p_x;
	int		p_y;
}				t_map;

typedef	struct	s_infos
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	moveSpeed;
	double	rotSpeed;
}				t_infos;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	t_graphics	graphics;
	t_map		map;
	t_infos		infos;
}				t_data;

#endif