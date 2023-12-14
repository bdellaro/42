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
	int		i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

char	*ft_print_line(char **temp)
{
	int		i;
	char	*line;
	char	*str;

	if (!*temp)
		return (NULL);
	str = *temp;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_strndup(str, i);
	*temp = ft_strndup(str + i, ft_strlen(str + i));
	if (str)
		free(str);
	str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*str;
	char			*buffer;
	int				n_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(str), str = NULL, NULL);
	if (ft_next(str))
		return (ft_print_line(&str));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	n_read = 1;
	while (n_read > 0)
	{
		n_read = read(fd, buffer, BUFFER_SIZE);
		buffer[n_read] = 0;
		str = ft_strjoin(str, buffer);
		if (ft_next(str))
			break ;
	}
	if (buffer)
		free(buffer);
	buffer = NULL;
	return (ft_print_line(&str));
}
/*
int	main(void)
{
	int fd = open("../File_descriptor", O_RDONLY);
	char	*str;
	
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break;
		printf("%s", str);
		free(str);
	}
	return (0);
}*/
