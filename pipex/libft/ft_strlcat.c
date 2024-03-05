/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:24:35 by bdellaro          #+#    #+#             */
/*   Updated: 2023/10/23 18:02:44 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dest);
	j = 0;
	if (n <= ft_strlen(dest))
		return (n + ft_strlen(src));
	while (src[j] && i < n - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (ft_strlen(dest) + ft_strlen(&src[j]));
}
/*int	main()
{
	char dest[] = "Test";
	char src[] = "icule";
	printf("%ld\n", ft_strlcat(dest, src, 2));
	return (0);
}*/
