/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:30:11 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/13 14:30:21 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_init_image(t_solong *solong)
{
	solong->img.img_exit = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_exit);
	solong->img.img_player = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_player);
	solong->img.img_wall = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_wall);
	solong->img.img_collect = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_collect);
	solong->img.img_stone = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_stone);
	solong->img.img_floor = mlx_texture_to_image \
		(solong->mlx, solong->tex.tex_floor);
	if (!solong->img.img_floor)
		ft_error_image(GRASS);
	if (!solong->img.img_stone)
		ft_error_image(STONE);
	if (!solong->img.img_exit)
		ft_error_image(EXIT);
	if (!solong->img.img_player)
		ft_error_image(PERSO);
	if (!solong->img.img_wall)
		ft_error_image(WALL);
	if (!solong->img.img_collect)
		ft_error_image(STAR);
}

void	ft_init_map(t_solong *solong)
{
	solong->map.y = 0;
	solong->map.x = 0;
	solong->window_height = solong->map.line_height * IMG_SIZE;
	solong->window_width = solong->map.line_width * IMG_SIZE;
}

int	ft_is_movable(t_solong *solong, char movement)
{
	return (ft_pull_next_card(solong, movement, \
	solong->content.wall) == SUCCESS \
	|| ft_pull_next_card(solong, movement, \
	solong->content.stone) == SUCCESS \
	|| (solong->content.exit_win == 0 \
	&& ft_pull_next_card(solong, movement, \
	solong->content.exit) == SUCCESS));
}

int	ft_collapse_img(t_solong *solong)
{
	ft_free_solong(solong);
	if (NULL != solong->img.img_wall)
		mlx_delete_image(solong->mlx, solong->img.img_wall);
	if (NULL != solong->img.img_floor)
		mlx_delete_image(solong->mlx, solong->img.img_floor);
	if (NULL != solong->img.img_player)
		mlx_delete_image(solong->mlx, solong->img.img_player);
	if (NULL != solong->img.img_collect)
		mlx_delete_image(solong->mlx, solong->img.img_collect);
	if (NULL != solong->img.img_exit)
		mlx_delete_image(solong->mlx, solong->img.img_exit);
	if (solong->img.img_stone != NULL)
		mlx_delete_image(solong->mlx, solong->img.img_stone);
	ft_delete_mlx(solong);
	return (0);
}

void	ft_collect_pot(t_solong *solong, char movement)
{
	if (((movement == 'w') && \
	solong->map.map[solong->map.player_y \
	- 1][solong->map.player_x] == solong->content.collect) \
	|| ((movement == 's') \
	&& solong->map.map[solong->map.player_y + \
	1][solong->map.player_x] == solong->content.collect) \
	|| ((movement == 'd') \
	&& solong->map.map[solong->map.player_y] \
	[solong->map.player_x + 1] == solong->content.collect) \
	|| ((movement == 'a') \
	&& solong->map.map[solong->map.player_y] \
	[solong->map.player_x - 1] == solong->content.collect))
	{
		solong->content.count_c--;
		solong->content.collected++;
	}
}
