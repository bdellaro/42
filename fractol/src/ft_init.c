/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:30:37 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/18 18:05:53 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

static void	malloc_error(void)
{
	perror("Malloc error");
	exit(EXIT_FAILURE);
}

/*static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, )
}
*/
int	ft_handle_input(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed.\n", keysym);
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	ft_printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

int	ft_string(t_fractal *fractal)
{
//	data->color = RED
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr, (WIDTH / 2) -
	45, HEIGHT - (HEIGHT / 11),
	RED, "Press ESC to quit !");
	return (0);
}

void	ft_fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		malloc_error();
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr,
			WIDTH, HEIGHT, fractal->name);
	if (fractal->win_ptr == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
//	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
/*	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}*/
	mlx_key_hook(fractal->win_ptr, ft_handle_input, fractal);
	mlx_loop_hook(fractal->mlx_ptr, ft_string, fractal);
	ft_printf("Press ESC to quit.\n");
	mlx_loop(fractal->mlx_ptr);
//	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
//			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}
