/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:30:37 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/25 19:13:07 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_error(void)
{
	ft_printf("MLX error\n");
	exit(EXIT_FAILURE);
}

void	ft_solong_init(t_solong *solong)
{
	solong->mlx = mlx_init(WIDTH, HEIGHT, solong->name, true);
	if (solong->mlx == NULL)
		ft_error();
	solong->texture = mlx_load_png("./sprites/test.png");
	if (solong->texture == NULL)
		ft_error();
//	mlx_set_window_size(solong->mlx, solong->texture->width, solong->texture->height);
	solong->img = mlx_texture_to_image(solong->mlx, solong->texture);
	mlx_resize_image(solong->img, WIDTH, HEIGHT);
	if (solong->img == NULL)
		ft_error();
	if (mlx_image_to_window(solong->mlx, solong->img, 0, 0) < 0)
		ft_error();
	mlx_loop(solong->mlx);
}
