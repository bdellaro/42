/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:57:03 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/20 12:57:58 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

static int	ft_is_valid_position(t_solong *solong, int y, int x)
{
	if (solong->map.map[y][x] != solong->content.wall \
	&& solong->map.map[y][x] != solong->content.stone)
		return (1);
	return (0);
}

static void	ft_bfs(t_solong *solong, int y, int x, int visited[][MAX_MAP_SIZE])
{
	int	queue[MAX_QUEUE_SIZE][2];
	int	f;
	int	r;
	int	dx[4] = {-1, 1, 0, 0};
	int	dy[4] = {0, 0, -1, 1};
	int	nx;
	int	ny;

	f = -1;
	r = -1;
	queue[++r][0] = y;
	queue[r][1] = x;
	visited[y][x] = 1;

	while (f != r)
	{
		int curr_y = queue[++f][0];
		int curr_x = queue[f][1];

		int i = -1;
		while (++i < 4)
		{
			ny = curr_y + dy[i];
			nx = curr_x + dx[i];

			if (ny >= 0 && ny < solong->map.line_height && nx >= 0 && nx < solong->map.line_width && !visited[ny][nx] && ft_is_valid_position(solong, ny, nx))
			{
				queue[++r][0] = ny;
				queue[r][1] = nx;
				visited[ny][nx] = 1;
			}
		}
	}
}

int	ft_is_playable(t_solong *solong)
{
	int	visited[MAX_MAP_SIZE][MAX_MAP_SIZE];
	int	py;
	int	px;
	int	i;
	int	j;

	py = solong->map.player_y;
	px = solong->map.player_x;

	i = -1;
	while (++i < solong->map.line_height)
	{
		j = -1;
		while (++j < solong->map.line_width)
			visited[i][j] = 0;
	}

	ft_bfs(solong, py, px, visited);

	i = -1;
	while (++i < solong->map.line_height)
	{
		j = -1;
		while (++j < solong->map.line_width)
		{
			if (solong->map.map[i][j] == solong->content.collect && !visited[i][j])
				return (0);
		}
	}

	return (1);
}
