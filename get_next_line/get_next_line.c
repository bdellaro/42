/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:26:54 by bdellaro          #+#    #+#             */
/*   Updated: 2023/12/12 11:27:07 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_next(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*ft_print_line(char **str)
{
	size_t	i;
	char	*line;
	char	*temp;

	if (!*str)
		return (NULL);
	temp = *str;
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	line = ft_strndup(temp, i);
	*str = ft_strndup(temp + i, ft_strlen(temp + i));
	free(temp);
	temp = NULL;
	return (line);
}

void	*ft_free(char **str, char **buffer)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*buffer;
	int			n_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!ft_next(str))
	{
		n_read = 1;
		while (n_read > 0)
		{
			n_read = read(fd, buffer, BUFFER_SIZE);
			if (n_read < 0)
				return (ft_free(&str, &buffer));
			buffer[n_read] = '\0';
			str = ft_strjoin(str, buffer);
			if (ft_next(str))
				break ;
		}
	}
	free(buffer);
	return (ft_print_line(&str));
}

int	main(void)
{
	int fd = open("File_descriptor.txt", O_RDONLY);
	char	*str;
	
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}
