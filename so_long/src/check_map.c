/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:30:00 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/13 14:30:21 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_check_vertical_borders(t_solong *solong)
{
	int	i;
	int	j;

	i = 0;
	j = solong->width - 1;
	while (i < solong->total_length)
	{
		if (solong->data_map[i] != '1')
		{
			ft_printf("Error\nLeft map border invalid\n");
			ft_free_solong(solong);
			exit(EXIT_FAILURE);
		}
		i++;
		if (solong->data_map[j] != '1')
		{
			ft_printf("Error\nRight map border invalid\n");
			ft_free_solong(solong);
			exit(EXIT_FAILURE);
		}
		j++;
		i += solong->width;
		j += solong->width;
	}
}

void	ft_check_map_line(t_solong *solong)
{
	int	i;

	i = 0;
	while (i < solong->width)
	{
		if (solong->data_map[i] != '1')
		{
			ft_printf("Error\nSuperior map border invalid\n");
			ft_free_solong(solong);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = solong->total_length - solong->width;
	while (i < solong->total_length - 1)
	{
		if (solong->data_map[i] != '1')
		{
			ft_printf("Error\nInferior map border invalid\n");
			ft_free_solong(solong);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_check_vertical_borders(solong);
}

int	ft_check_error_map(char *data_map, t_set *content, t_solong *solong)
{
	int	i;

	i = 0;
	while (data_map[i] != 0)
	{
		if (content->count_p > 1 || content->count_e > 1)
		{
			ft_printf("Error\nTo much player or to much exit into map\n");
			free(data_map);
			exit(EXIT_FAILURE);
		}
		if (ft_is_content(solong, i))
		{
			ft_printf("Error\nInvalid map\n");
			free(data_map);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_check_map_line(solong);
	return (0);
}

int	ft_check_content(t_solong *solong)
{
	int	i;
	int	map_check;

	i = 0;
	while (solong->data_map[i] != 0)
	{
		if (solong->data_map[i] == solong->content.player)
			solong->content.count_p++;
		if (solong->data_map[i] == solong->content.exit)
			solong->content.count_e++;
		if (solong->data_map[i] == solong->content.collect)
			solong->content.count_c++;
		i++;
	}
	ft_content_error(solong);
	map_check = ft_check_error_map(solong->data_map, \
		&solong->content, solong);
	ft_is_playable_map(solong);
	if (map_check == 0)
		ft_printf("  \033[1;35m[MAP OK]\033[0m\n\n");
	return (0);
}
