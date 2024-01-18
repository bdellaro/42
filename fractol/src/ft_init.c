/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:30:37 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/16 17:07:05 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

static void	malloc_error()
{
	perror("Malloc error");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->escaped_value = 4;
	fractal->iteration_definition = 42;
}

void	ft_fractal_init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		malloc_error();
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH,
	HEIGHT, fractal->name);
	if (fractal->win_ptr == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr,
	WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
	fractal->img.pixel_ptr =
	mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp,
	&fractal->img.line_len, &fractal->img.endian);
}

/*int	ft_init(char *fract)
{
	t_fractal	fractal;

	fractal.mlx_ptr = mlx_init();
	if (fractal.mlx_ptr == NULL)
	{
		ft_printf("Error : mlx_ptr/n");
		return (MLX_ERROR);
	}
	fractal.win_ptr = mlx_new_window(fractal.mlx_ptr, WIDTH, HEIGHT,
	fractal->name);
	if (fractal.win_ptr == NULL)
	{
		ft_mlx_error(&fractal);
		return (MLX_ERROR);
	}
	ft_printf("Window created.\n");
	mlx_loop(fractal.mlx_ptr);
	ft_mlx_free(&fractal);
	return (0);
}*/
