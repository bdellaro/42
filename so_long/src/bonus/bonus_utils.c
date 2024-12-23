/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:11:22 by bdellaro          #+#    #+#             */
/*   Updated: 2024/03/04 17:13:41 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_set_clean(t_solong *solong)
{
	solong->height = 0;
	solong->width = 0;
	solong->total_length = 0;
	solong->map.count = 0;
	solong->content.count_key = 0;
	solong->content.collected = 0;
	solong->content.stone = 'S';
	solong->content.exit_win = 0;
	solong->content.wall = '1';
	solong->content.floor = '0';
	solong->content.player = 'P';
	solong->content.exit = 'E';
	solong->content.enemy = 'X';
	solong->content.sl = '\n';
	solong->content.collect = 'C';
	solong->content.count_p = 0;
	solong->content.count_e = 0;
	solong->content.count_c = 0;
	solong->movement = 'd';
	solong->img.img_floor = NULL;
	solong->img.img_wall = NULL;
	solong->img.img_collect = NULL;
	solong->img.img_player = NULL;
	solong = NULL;
}

void	ft_delete_mlx(t_solong *solong)
{
	mlx_delete_texture(solong->tex.tex_wall);
	mlx_delete_texture(solong->tex.tex_exit);
	mlx_delete_texture(solong->tex.tex_player);
	mlx_delete_texture(solong->tex.tex_floor);
	mlx_delete_texture(solong->tex.tex_collect);
	mlx_delete_texture(solong->tex.tex_stone);
	mlx_delete_image(solong->mlx, solong->img.img_wall);
	mlx_delete_image(solong->mlx, solong->img.img_floor);
	mlx_delete_image(solong->mlx, solong->img.img_player);
	mlx_delete_image(solong->mlx, solong->img.img_collect);
	mlx_delete_image(solong->mlx, solong->img.img_exit);
	mlx_delete_image(solong->mlx, solong->img.img_stone);
	ft_delete_sup(solong);
	mlx_close_window(solong->mlx);
	mlx_terminate(solong->mlx);
	ft_free_2d(solong->map.map);
	free(solong->data_map);
	exit(EXIT_SUCCESS);
}

void	ft_free_solong(t_solong *solong)
{
	if (solong->data_map != NULL)
	{
		free(solong->data_map);
		solong->data_map = NULL;
	}
	else
		return ;
}

int	ft_is_content(t_solong *solong, int i)
{
	return (solong->data_map[i] != solong->content.player \
		&& solong->data_map[i] != solong->content.exit \
		&& solong->data_map[i] != solong->content.collect \
		&& solong->data_map[i] != solong->content.wall \
		&& solong->data_map[i] != solong->content.floor \
		&& solong->data_map[i] != solong->content.sl \
		&& solong->data_map[i] != solong->content.stone \
		&& solong->data_map[i] != solong->content.enemy);
}

void	ft_content_error(t_solong *solong)
{
	if (solong->content.count_p != 1 || \
		solong->content.count_e != 1 \
		|| solong->content.count_c == 0)
	{
		ft_printf("Error\n");
		if (solong->content.count_p != 1)
			ft_printf("Problem with player initialization : \
			%d P\n", solong->content.count_p);
		if (solong->content.count_e != 1)
			ft_printf("Problem with exit initialization : \
			%d E\n", solong->content.count_e);
		if (solong->content.count_c == 0)
			ft_printf("Missing something to collect\n");
		ft_free_solong(solong);
		exit(EXIT_FAILURE);
	}
}
