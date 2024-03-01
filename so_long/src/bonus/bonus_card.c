/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_card.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:10:26 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/28 14:14:20 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

int	ft_win_card_game(t_solong *solong)
{
	if (solong->content.exit_win == 1)
	{
		ft_printf("\033[32;5;1m");
		ft_printf("\n  YOU WIN !\n");
		ft_printf("\033[0m");
		ft_delete_mlx(solong);
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

int	ft_pull_next_card(t_solong *solong, char movement, char card)
{
	if ((movement == 'w' && \
		solong->map.map[solong->map.player_y - \
	1][solong->map.player_x] == card) || \
	(movement == 's' && \
	solong->map.map[solong->map.player_y +
	1][solong->map.player_x] \
	== card) || (movement == 'd' && \
	solong->map.map[solong->map.player_y][solong->map.player_x + 1] \
	== card) || (movement == 'a' && \
	solong->map.map[solong->map.player_y][solong->map.player_x - 1] \
	== card))
		return (SUCCESS);
	else
		return (FAILURE);
}

void	ft_card_path(t_solong *solong, char movement)
{
	ft_loose_game(solong, movement);
	if (ft_is_movable(solong, movement))
		return ;
	solong->map.count++;
	ft_collect_pot(solong, movement);
	ft_is_winable(solong);
	solong->map.map[solong->map.player_y] \
	[solong->map.player_x] = solong->content.floor;
	if (movement == 'w')
		ft_key_w(solong);
	else if (movement == 's')
		ft_key_s(solong);
	else if (movement == 'd')
		ft_key_d(solong);
	else if (movement == 'a')
		ft_key_a(solong);
	if (solong->content.exit_win == 1 && solong->map.map[solong->map. \
	player_y][solong->map.player_x] == solong->content.exit)
		ft_win_card_game(solong);
	solong->map.map[solong->map.player_y] \
	[solong->map.player_x] = solong->content.player;
	ft_dispatch_cards(solong);
}

void	ft_fill_cards(t_solong *solong, int width, int y, int x)
{
	if (solong->map.map[y][x] == solong->content.wall)
		mlx_image_to_window(solong->mlx, \
		solong->img.img_wall, width, y * IMG_SIZE);
	if (solong->map.map[y][x] == solong->content.floor)
		mlx_image_to_window(solong->mlx, \
		solong->img.img_floor, width, y * IMG_SIZE);
	else if (solong->movement == 'a')
		ft_player_a(solong);
	else if (solong->movement == 'w')
		ft_player_w(solong);
	else if (solong->movement == 's')
		ft_player_s(solong);
	else if (solong->map.map[y][x] == solong->content.player)
		mlx_image_to_window(solong->mlx, \
		solong->img.img_player, width, y * IMG_SIZE);
}

int	ft_dispatch_cards(t_solong *solong)
{
	int		width;
	int		y;
	int		x;

	y = 0;
	x = 0;
	width = 0;
	while (solong->map.map[y])
	{
		while (solong->map.map[y][x] && solong->map.map[y][x] != '\0')
		{
			ft_fill_cards(solong, width, y, x);
			width += IMG_SIZE;
			x++;
		}
		x = 0;
		width = 0;
		y++;
	}
	return (0);
}
