/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:09:51 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/29 18:10:07 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_enemy_2(t_solong *solong)
{
	int	x;
	int	y;

	y = 0;
	while (y < solong->height)
	{
		x = 0;
		while (x < solong->width)
		{
			if (solong->map.map[y][x] == 'X')
			{
				if (solong->img.img_enemy_b != NULL)
				{
					mlx_image_to_window \
					(solong->mlx, \
					solong->img.img_enemy_b, \
					x * IMG_SIZE, y * IMG_SIZE);
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_enemy_1(t_solong *solong)
{
	int	x;
	int	y;

	y = 0;
	while (y < solong->height)
	{
		x = 0;
		while (x < solong->width)
		{
			if (solong->map.map[y][x] == 'X')
			{
				if (solong->img.img_enemy != NULL)
				{
					mlx_image_to_window \
					(solong->mlx, \
					solong->img.img_enemy, \
					x * IMG_SIZE, y * IMG_SIZE);
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_star_b(t_solong *solong)
{
	int	x;
	int	y;

	y = 0;
	while (y < solong->height)
	{
		x = 0;
		while (x < solong->width)
		{
			if (solong->map.map[y][x] == 'C')
			{
				if (solong->img.img_collect_b != NULL)
				{
					mlx_image_to_window \
					(solong->mlx, \
					solong->img.img_collect_b, \
					x * IMG_SIZE, y * IMG_SIZE);
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_player_a(t_solong *solong)
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
				if (solong->img.img_player_a != NULL)
				{
					mlx_image_to_window \
					(solong->mlx, \
					solong->img.img_player_a, \
					x * IMG_SIZE, y * IMG_SIZE);
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_wall(t_solong *solong)
{
	int	x;
	int	y;

	y = 0;
	while (y < solong->height)
	{
		x = 0;
		while (x < solong->width)
		{
			if (solong->map.map[y][x] == 'x')
			{
				if (solong->img.img_wall != NULL)
				{
					mlx_image_to_window \
					(solong->mlx, \
					solong->img.img_wall, \
					x * IMG_SIZE, y * IMG_SIZE);
				}
			}
			x++;
		}
		y++;
	}
}
