#include "../include/so_long.h"

void	ft_free_solong(t_solong *solong)
{
	if (solong->data_map != NULL)
	{
		free(solong->data_map);
		solong->data_map = NULL;
	}
}

void	ft_read_map(char *map, t_solong *solong)
{
	int		fd;
	int		line_length;
	char	*line;
	char	*temp;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap not found");
		ft_free_solong(solong);
		exit(EXIT_FAILURE);
	}
	solong->height = 0;
	solong->width = 0;
	solong->total_length = 0;
	solong->data_map = malloc(1);
	if (solong->data_map == NULL)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	solong->data_map[0] = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		line_length = ft_strlen(line);
		solong->total_length += line_length;
		if (solong->height == 0)
			solong->width = (line_length - 1);
		temp = solong->data_map;
		solong->data_map = ft_strjoin(solong->data_map,
		line);
		ft_printf("   %s", line);
		free(temp);
		free(line);
		solong->height++;
	}
	ft_printf("\n");
	if (solong->height == 0 || solong->total_length == 0)
	{
		ft_printf("Error\nEmpty map\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (solong->height == solong->width)
	{
		ft_printf("Error\nMap is not rectangular");
		ft_free_solong(solong);
		exit(EXIT_FAILURE);
	}
	close(fd);
}



int	ft_size_of_map(char **map)
{
	int count = 0;
	while (map[count] != NULL) {
		count++;
	}
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
		y++;
	solong->map.line_height = ft_size_of_map(solong->map.map);
	solong->map.line_width = (ft_strlen(solong->map.map[0]));
}
