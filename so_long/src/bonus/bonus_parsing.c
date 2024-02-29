/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:11:03 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/28 14:14:20 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_free_visited(t_solong *solong)
{
	int	y;

	y = 0;
	while (y < solong->height)
	{
		free(solong->visited[y]);
		y++;
	}
	free(solong->visited);
}

void	ft_compare_count_items(t_solong *solong)
{
	if (solong->content.count_c != solong->visited_items)
	{
		ft_printf("Error\nItems uncollectables\n");
		ft_free_solong(solong);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("  \033[1;35m[MAP OK]\033[0m\n\n");
		return ;
	}
}

void	ft_visit(t_solong *solong, int y, int x, int **visited)
{
	if (solong->map.map[y][x] == '1' || visited[y][x] \
	|| solong->map.map[y][x] == 'S' || solong->map.map[y][x] \
	== 'X')
		return ;
	visited[y][x] = 1;
	if (solong->map.map[y][x] == 'E')
	{
		solong->path_found = 1;
		return ;
	}
	else if (solong->map.map[y][x] == 'C')
		solong->visited_items = solong->visited_items + 1;
	ft_visit(solong, y + 1, x, visited);
	ft_visit(solong, y - 1, x, visited);
	ft_visit(solong, y, x + 1, visited);
	ft_visit(solong, y, x - 1, visited);
}

void	ft_find_start_position(t_solong *solong, int *start_y, int *start_x)
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
				*start_y = y;
				*start_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_valid_path(t_solong *solong)
{
	int	y;
	int	start_x;
	int	start_y;

	start_x = 0;
	start_y = 0;
	y = 0;
	solong->visited_items = 0;
	solong->visited = malloc(sizeof(int *) * solong->height);
	while (y < solong->height)
	{
		solong->visited[y] = ft_calloc(solong->width, sizeof(int));
		y++;
	}
	solong->path_found = 0;
	ft_find_start_position(solong, &start_y, &start_x);
	ft_visit(solong, start_y, start_x, solong->visited);
	if (!solong->path_found)
	{
		ft_free_visited(solong);
		ft_printf("Error\nNo valid path found\n");
		exit(EXIT_FAILURE);
	}
	ft_free_visited(solong);
	ft_compare_count_items(solong);
}
