#include "../includes/so_long.h"

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

// Récupérer le nombre de lignes dans le fichier .ber
int	retrieve_line_number(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_printf("Error\nOpen failed\n");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

void	put_input_in_map(int row, int column, int i, t_solong *data)
{
	char	*line;

	line = get_next_line(solong->map.fd);
	while (line != NULL)
	{
		solong->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!solong->map.map[row])
			return (ft_free(solong->map.map));
		while (line[i] != '\0')
			solong->map.map[row][column++] = line[i++];
		solong->map.map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(solong->map.fd);
	}
	solong->map.map[row] = NULL;
}

void	create_map(char *path, t_solong *solong)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	solong->map.line_count = retrieve_line_number(path);
	solong->map.path = path;
	solong->map.map = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(solong->map.map))
		return ;
	solong->map.fd = open(path, O_RDONLY);
	if (solong->map.fd < 0)
		printf("Error\nOpen failed\n");
	else
	{
		put_input_in_map(row, column, i, solong);
		close(solong->map.fd);
	}
}
