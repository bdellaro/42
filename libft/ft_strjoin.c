/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:30:28 by bdellaro          #+#    #+#             */
/*   Updated: 2023/11/29 13:36:18 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*s3;

	i = 0;
	j = 0;
	k = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * (k + 1));
	if (!s3 || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[k] = 0;
	return (s3);
}
/*int	main(void)
{
	char	s1[] = "Test";
	char	s2[] = "icule";

	printf("Retour s3 : %s", ft_strjoin(s1, s2));
	return (0);
}*/
