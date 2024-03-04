/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:21:11 by bdellaro          #+#    #+#             */
/*   Updated: 2024/03/04 15:46:38 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_is_winable(t_solong *solong)
{
	if (solong->content.count_c == 0)
		solong->content.exit_win = 1;
	return ;
}

void	ft_free_2d(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return ;
}

void	ft_free_array(mlx_image_t **arr, t_solong *solong)
{
	while (arr)
	{
		free(arr);
		arr++;
	}
	ft_free_2d(solong->map.map);
	return ;
}

t_solong	*ft_create_solong(void)
{
	t_solong	*solong;

	solong = (t_solong *)malloc(sizeof(t_solong));
	if (solong == NULL)
	{
		ft_printf("Error\nAllocation failed for game structure\n");
		exit(EXIT_FAILURE);
	}
	ft_set_clean(solong);
	return (solong);
}

void	ft_clean(t_solong *solong)
{

	if (solong->tex.tex_wall)
		mlx_delete_texture(solong->tex.tex_wall);
	if (solong->tex.tex_floor)
		mlx_delete_texture(solong->tex.tex_floor);
	if (solong->tex.tex_player)
		mlx_delete_texture(solong->tex.tex_player);
	if (solong->tex.tex_collect)
		mlx_delete_texture(solong->tex.tex_collect);
	if (solong->tex.tex_exit)
		mlx_delete_texture(solong->tex.tex_exit);

}

