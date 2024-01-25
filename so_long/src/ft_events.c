#include "../include/so_long.h"

int	ft_handle_input(int keysym, t_solong *solong)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed.\n", keysym);
		ft_mlx_exit(solong);
	}
	ft_printf("The %d key has been pressed\n\n", keysym);
	/*mlx_string_put(solong->mlx_ptr, solong->win_ptr, (WIDTH / 2) -
        45, HEIGHT - (HEIGHT / 20),
        RED, ft_itoa(keysym));*/
	return (0);
}

int	ft_string_on_window(t_solong *solong)
{
//	data->color = RED
	mlx_string_put(solong->mlx_ptr, solong->win_ptr, (WIDTH / 2) -
	45, HEIGHT - (HEIGHT / 11),
	RED, "Press ESC to quit !");
	return (0);
}

/*int	ft_put_key(int keysym, t_solong *solong)
{
	mlx_string_put(solong->mlx_ptr, solong->win_ptr, (WIDTH / 2) -
        45, HEIGHT - (HEIGHT / 11),
        RED, ft_itoa(keysym));
	return (0);
}*/
