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
	if (argc == 1 || argc > 4)// || (ft_strncmp(argv[1], "julia", 5) != 0)
	//	|| (ft_strncmp(argv[1], "mandelbrot", 10) != 0))
	{
			ft_printf("Invalid argument(s).\n");
			ft_printf("Please enter :\n\n===> mandelbrot\nOr\n");
			ft_printf("===> julia [value 1] [value 2]\n");
	}
	else
	{
		if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		{
			ft_printf("\n===> Mandelbroot fractal chosen.\n");
			ft_init("Mandelbrot fract-ol");
		}
		if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 3)
			ft_printf("Missing one argument for Julia fractal\n");
		if (ft_strncmp(argv[1], "julia", 5) == 0 && argc > 4)
			ft_printf("Too few arguments for Julia fractal\n");
		if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4)
		{	
			ft_printf("\n===> Julia fractal chosen.\n");
			ft_init("Julia fract-ol");
		}
	}
	return (0);
}
