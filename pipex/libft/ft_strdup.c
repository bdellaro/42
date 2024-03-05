/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:57:23 by bdellaro          #+#    #+#             */
/*   Updated: 2023/10/24 13:03:45 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str2;
	size_t	n;

	n = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!str2)
		return (NULL);
	while (str[n])
	{
		str2[n] = str[n];
		n++;
	}
	str2[n] = 0;
	return (str2);
}
/*int	main()
{
	const char str[] = "Encore un test";

	printf("%s\n", ft_strdup(str));
	return (0);
}*/
