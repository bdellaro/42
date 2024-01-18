/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:47:50 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/16 15:03:02 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_mlx_error(t_fractal *fractal)
{
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->win_ptr);
	free(fractal->mlx_ptr);
	ft_printf("Error : no window created\n");
	return (MLX_ERROR);
}

void	ft_mlx_free(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
}
