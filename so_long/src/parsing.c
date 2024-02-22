#include "../include/so_long.h"

int	ft_valid_move(t_solong *solong, int **visited, int row, int col)
{
	ft_printf("row = %d, col = %d\n", row, col);
	ft_printf("map content = %c", solong->map.map[row][col]);
	return (solong->map.map[row][col] != '1' && !visited[row][col]);
}

void	ft_flood_fill(t_solong *solong, int row, int col, int **visited)
{
	if (!ft_valid_move(solong, visited, row, col) || visited[row][col])
		return ;
	if (solong->map.map[row][col] == 'C')
		solong->content.count_stars += 1;
	visited[row][col] = 1;
	ft_flood_fill(solong, row - 1, col, visited);
	ft_flood_fill(solong, row + 1, col, visited);
	ft_flood_fill(solong, row, col - 1, visited);
	ft_flood_fill(solong, row, col + 1, visited);
}

void	ft_player_position(t_solong *solong, int i, int *player_col, int *player_row)
{
	int	j;

	j = 0;
	solong->collect_stars = 0;
	while (solong->map.map[i][j])
	{
		if (solong->map.map[i][j] == 'P')
		{
			*player_row = i;
			*player_col = j;
			break ;
		}
		j++;
	}
}

void	ft_exit_position(t_solong *solong)
{
	int	j;
	int	i;

	i = 0;
	while (solong->map.map[i])
	{
		j = 0;
		while (solong->map.map[i][j])
		{
			if (solong->map.map[i][j] == 'E')
			{
				solong->map.x = i;
				solong->map.y = j;
			}
			if (solong->map.map[i][j] == 'C')
				solong->collect_stars += 1;
			j++;
		}
		i++;
	}
}

int	ft_valid_path(t_solong *solong)
{
	int	i;
	int	p_row;
	int	p_col;
	int	**visited;

	solong->content.count_stars = solong->content.count_c;
	visited = ft_calloc(solong->map.height, sizeof(int *));
	i = 0;
	while (i < solong->map.height)
	{
		visited[i] = ft_calloc(solong->map.width, sizeof(int));
		i++;
	}
	i = 0;
	p_row = 0;
	p_col = 0;
	while (solong->map.map[i])
	{
		ft_player_position(solong, i, &p_col, &p_row);
		i++;
	}
	ft_exit_position(solong);
	ft_flood_fill(solong, p_row, p_col, visited);
	i = visited[p_row][p_col] && visited[solong->map.x][solong->map.y];
	free(visited);
	if (solong->content.count_stars != solong->collect_stars || !i)
	{
		ft_free_solong(solong);
		return (1);
	}
	return (0);
}
