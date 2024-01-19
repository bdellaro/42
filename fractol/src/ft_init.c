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
	mlx_key_hook(fractal->win_ptr, ft_handle_input, fractal);
	mlx_loop_hook(fractal->mlx_ptr, ft_string_on_window, fractal);
	ft_printf("Press ESC to quit.\n");
	mlx_loop(fractal->mlx_ptr);
}
