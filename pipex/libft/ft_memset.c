/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:59:50 by bdellaro          #+#    #+#             */
/*   Updated: 2023/10/20 12:59:52 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}
/*int	main()
{
	char str[] = "Je devrais faire une pause";

	printf("\n%s\n\n", str);
	printf("Avec memset(str, '>', 10) :\n\n");

	ft_memset(str, '>', 10);

	printf("%s\n\n", str);

	return (0);
}*/
