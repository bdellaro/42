/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:10:46 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/28 14:14:20 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_init_player(t_solong *solong)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (solong->map.map[y])
	{
		x = 0;
		while (solong->map.map[y][x])
		{
			if (solong->map.map[y][x] == solong->content.player)
			{
				solong->content.exit_win = 0;
				solong->map.player_y = y;
				solong->map.player_x = x;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_struct_image(t_solong *solong)
{
	solong->tex.tex_stone = mlx_load_png(STONE);
	solong->tex.tex_floor = mlx_load_png(GRASS);
	solong->tex.tex_wall = mlx_load_png(WALL);
	solong->tex.tex_exit = mlx_load_png(EXIT);
	solong->tex.tex_collect = mlx_load_png(STAR);
	solong->tex.tex_player = mlx_load_png(PERSO);
	if (!solong->tex.tex_stone)
		ft_error_image(STONE);
	if (!solong->tex.tex_floor)
		ft_error_image(GRASS);
	if (!solong->tex.tex_exit)
		ft_error_image(EXIT);
	if (!solong->tex.tex_player)
		ft_error_image(PERSO);
	if (!solong->tex.tex_wall)
		ft_error_image(WALL);
	if (!solong->tex.tex_collect)
		ft_error_image(STAR);
	ft_bonus_texture(solong);
}

void	ft_solong_init(char *map, t_solong *solong, int arg)
{
	ft_set_clean(solong);
	ft_read_map(map, solong);
	ft_check_content(solong);
	ft_map_to_2d(solong);
	ft_struct_image(solong);
	ft_init_player(solong);
	ft_init_map(solong);
	ft_valid_path(solong);
	solong->mlx = mlx_init(solong->window_width, \
	solong->window_height, solong->name, true);
	if (arg == 1)
		free(solong->name);
	if (solong->mlx == NULL)
		ft_error();
	ft_init_image(solong);
	ft_write(solong);
	ft_wall(solong);
	ft_stone(solong);
	ft_exit(solong);
	ft_dispatch_cards(solong);
	ft_hook(solong);
	mlx_key_hook(solong->mlx, &ft_print_key, solong);
	mlx_loop_hook(solong->mlx, &ft_animation, solong);
	mlx_loop(solong->mlx);
	ft_delete_mlx(solong);
}

int	ft_size_of_map(char **map)
{
	int	count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}

void	ft_map_to_2d(t_solong *solong)
{
	int	y;

	y = 0;
	solong->map.map = ft_split(solong->data_map, '\n');
	if (solong->map.map == NULL)
	{
		ft_printf("Error\nProblem while converting map to 2D array");
		exit(EXIT_FAILURE);
	}
	while (solong->map.map[y] != NULL)
	{
		y++;
	}
	solong->map.line_height = ft_size_of_map(solong->map.map);
	solong->map.line_width = (ft_strlen(solong->map.map[0]));
}
