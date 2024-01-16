/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:30:37 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/12 17:12:08 by bdellaro         ###   ########.fr       */
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
		ft_mlx_error(data.mlx_ptr, data.win_ptr);
		return (MLX_ERROR);
	}
	ft_printf("Window created.\n");
	ft_printf("\nPress ESC to quit window.\n");
	mlx_loop(data.mlx_ptr);
	ft_mlx_free(data.mlx_ptr, data.win_ptr);
	/*void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		ft_printf("Error : mlx_ptr\n");
		return (MLX_ERROR);
	}
	win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, fract);
	if (win_ptr == NULL)
	{
		ft_mlx_error(mlx_ptr, win_ptr);
	}
	ft_printf("Window created.\n");
	ft_printf("\nPress ESC to quit window.\n");
	mlx_loop(mlx_ptr);
	ft_mlx_free(mlx_ptr, win_ptr);*/
	return (0);
}
