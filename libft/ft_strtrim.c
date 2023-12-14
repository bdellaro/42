/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:44 by bdellaro          #+#    #+#             */
/*   Updated: 2023/10/25 09:28:54 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_verify(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	n;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_verify(((char)*s1), set))
			s1++;
		else
			break ;
	}
	n = ft_strlen(s1);
	while (n != 0)
	{
		if (ft_verify(s1[n - 1], set))
			n--;
		else
			break ;
	}
	s2 = (char *)malloc(sizeof(char) * n + 1);
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, (char *)s1, n + 1);
	return (s2);
}
