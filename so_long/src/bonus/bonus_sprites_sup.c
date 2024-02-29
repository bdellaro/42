/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sprites_sup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:58:14 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/29 19:58:17 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_player_s(t_solong *solong)
{
	int	x;
	int	y;

	y = 0;
	while (y < solong->height)
	{
		x = 0;
		while (x < solong->width)
		{
			if (solong->map.map[y][x] == 'P')
			{
				if (solong->img.img_player_s != NULL)
				{
					mlx_image_to_window \
					(solong->mlx, \
					solong->img.img_player_s, \
					x * IMG_SIZE, y * IMG_SIZE);
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_player(t_solong *solong)
{
	int	x;
	int	y;

	y = 0;
	while (y < solong->height)
	{
		x = 0;
		while (x < solong->width)
		{
			if (solong->map.map[y][x] == 'P')
			{
				if (solong->img.img_player != NULL)
				{
					mlx_image_to_window \
					(solong->mlx, \
					solong->img.img_player, \
					x * IMG_SIZE, y * IMG_SIZE);
				}
			}
			x++;
		}
		y++;
	}
}
