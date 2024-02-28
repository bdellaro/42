#include "../include/so_long_bonus.h"

void	ft_handle_error(int fd)
{
	ft_printf("Error\nMap not found\n");
	close(fd);
	exit(EXIT_FAILURE);
}

void	ft_initialize_solong(t_solong *solong)
{
	solong->height = 0;
	solong->width = 0;
	solong->total_length = 0;
	solong->data_map = malloc(1);
	if (solong->data_map == NULL)
	{
		ft_printf("Error\nMemory allocation failed");
		exit(EXIT_FAILURE);
	}
	solong->data_map[0] = 0;
}

void	ft_read_map_data(int fd, t_solong *solong)
{
	char	*line;
	int		line_length;
	char	*temp;

	line = get_next_line(fd);
	while (line != NULL)
	{
		line_length = ft_strlen(line);
		solong->total_length += line_length;
		if (solong->height == 0)
			solong->width = (line_length - 1);
		temp = solong->data_map;
		solong->data_map = ft_strjoin(solong->data_map, line);
		ft_printf("   %s", line);
		free(temp);
		free(line);
		line = get_next_line(fd);
		solong->height++;
	}
	ft_print_map_error(solong, fd);
}

void	ft_read_map(char *map, t_solong *solong)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_handle_error(fd);
		return ;
	}
	ft_initialize_solong(solong);
	ft_read_map_data(fd, solong);
	close(fd);
}
