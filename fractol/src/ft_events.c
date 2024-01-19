#include "../include/fractol.h"

int	ft_handle_input(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed.\n", keysym);
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		exit(EXIT_SUCCESS);
		ft_printf("The %d key has been pressed\n\n", keysym);
	}
/*	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, (WIDTH / 2) -
        45, HEIGHT - (HEIGHT / 11),
        RED, ft_itoa(keysym));*/
	return (0);
}

int	ft_string_on_window(t_fractal *fractal)
{
//	data->color = RED
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, (WIDTH / 2) -
	45, HEIGHT - (HEIGHT / 11),
	RED, "Press ESC to quit !");
	return (0);
}

/*int	ft_put_key(int keysym, t_fractal *fractal)
{
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, (WIDTH / 2) -
        45, HEIGHT - (HEIGHT / 11),
        RED, ft_itoa(keysym));
	return (0);
}*/
