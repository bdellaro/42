/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:27:56 by bdellaro          #+#    #+#             */
/*   Updated: 2023/12/12 11:28:00 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strndup_gnl(char *str, int len)
{
	char	*array;
	int		count;
	char	*result;
	if (!str || !len)
		return (NULL);
	count = -1;
	array = (char *)malloc((len + 1) * sizeof(char));
	while (++count < len)
		array[count] = str[count];
	array[count] = '\0';
	result = array;
	return (result);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	int		len;
	char	*array;
	char	*result;

	i = 0;
	len = ft_strlen_gnl(s2);
	if (!s1)
		return (ft_strndup_gnl(s2, len));
	len = len + ft_strlen_gnl(s1);
	array = (char *)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (NULL);
	len = 0;
	while (s1[i])
		array[len++] = s1[i++];
	i = 0;
	while (s2[i])
		array[len++] = s2[i++];
	array[len] = '\0';
	free(s1);
	result = array;
	free(array);
	return (result);
}

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
