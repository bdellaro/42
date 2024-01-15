/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:53:07 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/12 16:53:11 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Please choose :\n===> 1 for Mandelbrot\n");
		ft_printf("===> 2 for Julia\n");
	}
	else
	{
		if (ft_strncmp(argv[1], "1", 1) == 0)
		{
			ft_printf("\n===> Mandelbroot fractal chosen.\n");
			ft_init("Mandelbrot fract-ol");
		}
		if (ft_strncmp(argv[1], "2", 1) == 0)
			
		{	ft_printf("\n===> Julia fractal chosen.\n");
			ft_init("Julia fract-ol");
		}
	}
	return (0);
}
