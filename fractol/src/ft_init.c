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



int	ft_init(char *fract)
{
	t_mlx_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
	{
		ft_printf("Error : mlx_ptr/n");
		return (MLX_ERROR);
	}
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, fract);
	if (data.win_ptr == NULL)
	{
		ft_mlx_error(&data);
		return (MLX_ERROR);
	}
	ft_printf("Window created.\n");
	mlx_loop(data.mlx_ptr);
	ft_mlx_free(&data);
	return (0);
}
