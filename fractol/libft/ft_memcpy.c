/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:58:00 by bdellaro          #+#    #+#             */
/*   Updated: 2023/10/23 17:41:58 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*int	main()
{
	char	dest[25];
	char	src[] = "Doubidouwap";
	printf("%p\n", dest);
	printf("%p\n", src);
	printf("%p\n\n", ft_memcpy(dest, src, 99));
	printf("%s\n", dest);
	return (0);
}*/
