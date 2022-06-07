#include "cub3d.h"

int    handle_crossbtn(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    data->win = NULL;
    mlx_destroy_display(data->mlx);
    free_for_your_life(data);
    exit(0);
    return (0);
}

int    handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx, data->win);
        data->win = NULL;
        printf("j'ai fait le taff\n");
        mlx_destroy_display(data->mlx);
        free_for_your_life(data);
        exit(0);
    }
    // else if (ft_strchr("wasd", keysym))
    //     move_player(data, keysym);
    return (0);
}