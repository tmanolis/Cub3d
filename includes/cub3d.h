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
# include "../minilibx_linux/mlx.h"

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

enum e_output
{
	SUCCESS = 0,
	FAILURE = 1,
	ERROR = 2
};

// 00_ERROR_HANDLING - 00_check_arg.c
int	check_arg(char *arg);


#endif