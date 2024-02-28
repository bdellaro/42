/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:21:11 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/14 16:21:20 by bdellaro         ###   ########.fr       */
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
		ft_printf("Error\nAllocation failed for solong\n");
		exit(EXIT_FAILURE);
	}
	ft_set_clean(solong);
	return (solong);
}
