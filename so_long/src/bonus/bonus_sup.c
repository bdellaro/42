/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:09:55 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/29 18:10:07 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_bonus_texture(t_solong *solong)
{
	solong->tex.tex_enemy = mlx_load_png(ENEMY);
	solong->tex.tex_enemy_b = mlx_load_png(ENEMY_B);
	solong->tex.tex_collect_b = mlx_load_png(STAR_B);
	solong->tex.tex_player_a = mlx_load_png(PERSO_A);
	if (!solong->tex.tex_enemy)
		ft_error_image(ENEMY);
	if (!solong->tex.tex_enemy_b)
		ft_error_image(ENEMY_B);
	if (!solong->tex.tex_collect_b)
		ft_error_image(STAR_B);
	if (!solong->tex.tex_player_a)
		ft_error_image(PERSO_A);
}

void	ft_bonus_image(t_solong *solong)
{
	solong->img.img_enemy = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_enemy);
	solong->img.img_enemy_b = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_enemy_b);
	solong->img.img_collect_b = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_collect_b);
	solong->img.img_player_a = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_player_a);
	if (!solong->img.img_enemy)
		ft_error_image(ENEMY);
	if (!solong->img.img_enemy_b)
		ft_error_image(ENEMY_B);
	if (!solong->img.img_collect_b)
		ft_error_image(STAR_B);
	if (!solong->img.img_player_a)
		ft_error_image(PERSO_A);
}

void	ft_bonus_collapse(t_solong *solong)
{
	if (NULL != solong->img.img_enemy)
		mlx_delete_image(solong->mlx, solong->img.img_enemy);
	if (NULL != solong->img.img_enemy_b)
		mlx_delete_image(solong->mlx, solong->img.img_enemy_b);
	if (NULL != solong->img.img_collect_b)
		mlx_delete_image(solong->mlx, solong->img.img_collect_b);
	if (NULL != solong->img.img_player_a)
		mlx_delete_image(solong->mlx, solong->img.img_player_a);
}

int	ft_loose_game(t_solong *solong, char movement)
{
	if ((movement == 'w' && \
		solong->map.map[solong->map.player_y - \
		1][solong->map.player_x] == 'X') || \
		(movement == 's' && \
		solong->map.map[solong->map.player_y +
		1][solong->map.player_x] \
		== 'X') || (movement == 'd' && \
		solong->map.map[solong->map.player_y] \
		[solong->map.player_x + 1] \
		== 'X') || (movement == 'a' && \
		solong->map.map[solong->map.player_y] \
		[solong->map.player_x - 1] == 'X'))
	{
		ft_printf("\033[31;5;1m");
		ft_printf("\n  YOU LOOSE !\n");
		ft_printf("\033[0m");
		ft_delete_mlx(solong);
	}
	return (SUCCESS);
}

void	ft_star(t_solong *solong)
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
				if (solong->img.img_collect != NULL)
				{
					mlx_image_to_window \
					(solong->mlx, \
					solong->img.img_collect, \
					x * IMG_SIZE, y * IMG_SIZE);
				}
			}
			x++;
		}
		y++;
	}
}
