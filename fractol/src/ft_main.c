/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:53:07 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/16 18:11:57 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10) 
			&& ft_strncmp(argv[1], "mandelbrot", 11) == 0)
				|| (argc > 1 && !ft_strncmp(argv[1], "julia",
					5) && ft_strncmp(argv[1], "julia", 11) == 0 ))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
		{
			ft_printf("===> Mandelbroot fractal chosen.\n");
			ft_fractal_init(&fractal);
			fractal_render(&fractal);
			mlx_loop(fractal.mlx_ptr);
		}
		if (!ft_strncmp(argv[1], "julia", 5) && argc == 2)
			ft_printf("Enter two values for Julia fractal\n");
		if (!ft_strncmp(argv[1], "julia", 5) && argc == 3)
			ft_printf("Missing one argument for Julia fractal\n");
		if (!ft_strncmp(argv[1], "julia", 5) && argc > 4)
			ft_printf("Too few arguments for Julia fractal\n");
		if (!ft_strncmp(argv[1], "julia", 5) && argc == 4)
		{	
			ft_printf("===> Julia fractal chosen.\n");
			ft_fractal_init(&fractal);
		}
	}
	else
	{
			ft_printf("Invalid argument(s).\n");
			ft_printf("Please enter :\n      ===> mandelbrot\n   Or\n");
			ft_printf("      ===> julia [value 1] [value 2]\n");
	}
	return (0);
}
