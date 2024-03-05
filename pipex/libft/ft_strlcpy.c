/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 08:24:29 by bdellaro          #+#    #+#             */
/*   Updated: 2023/10/23 18:37:12 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
	{
		dest[i] = 0;
		i++;
	}
	return (ft_strlen(src));
}
/*int	main()
{
	char dest[2];
	const char src[] = "Croissinou";

	printf("Taille retour ft_ : %ld\n", ft_strlcpy(dest, src, 5));
	return (0);
}*/
