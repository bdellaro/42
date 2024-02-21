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

int	ft_is_valid_position(t_solong *solong, int row, int col)
{
	if (solong->parsing_map[row][col] != '1' && solong->parsing_map[row][col] != '2')
		return (1);
	else
		return (0);
}

void	ft_explore_map_helper(t_solong *solong, int curr_row, int curr_col)
{
	int	new_row;
	int	new_col;
	int	i;

	i = 0;
	while (i < 4)
	{
		new_row = curr_row + solong->dy[i];
		new_col = curr_col + solong->dx[i];

		if (new_row >= 0 && new_row < solong->parsing_line_height &&
			new_col >= 0 && new_col < solong->parsing_line_width &&
			!solong->visited[new_row][new_col])
		{
			if (ft_is_valid_position(solong, new_row, new_col))
			{
				solong->rear++;
				solong->queue[solong->rear][0] = new_row;
				solong->queue[solong->rear][1] = new_col;
				solong->visited[new_row][new_col] = 1;
			}
		}
		i++;
	}
}

void	ft_process_queue(t_solong *solong)
{
	while (solong->front != solong->rear)
	{
		solong->front++;
		int curr_row = solong->queue[solong->front][0];
		int curr_col = solong->queue[solong->front][1];

		ft_explore_map_helper(solong, curr_row, curr_col);
	}
}

void	ft_explore_map(t_solong *solong)
{
	solong->front = -1;
	solong->rear = -1;
	solong->dx[0] = -1;
	solong->dx[1] = 1;
	solong->dx[2] = 0;
	solong->dx[3] = 0;
	solong->dy[0] = 0;
	solong->dy[1] = 0;
	solong->dy[2] = -1;
	solong->dy[3] = 1;

	solong->rear++;
	solong->queue[solong->rear][0] = solong->player_x;
	solong->queue[solong->rear][1] = solong->player_y;
	solong->visited[solong->player_x][solong->player_y] = 1;

	ft_process_queue(solong);
}

int	ft_is_playable_map(t_solong *solong)
{
	int	i;
	int	j;

	ft_explore_map(solong);
	i = 0;
	while (i < solong->parsing_line_height)
	{
		j = 0;
		while (j < solong->parsing_line_width)
		{
			if (solong->parsing_map[i][j] == 'C' && !solong->visited[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
