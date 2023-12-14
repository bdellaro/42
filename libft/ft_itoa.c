/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:28:11 by bdellaro          #+#    #+#             */
/*   Updated: 2023/10/25 11:49:40 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static char	*ft_char(char *str, unsigned int nbr, size_t i)
{
	while (nbr > 0)
	{
		str[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i--;
	}
	return (str);
}

static size_t	ft_len(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	nbr;
	int				sign;

	sign = 1;
	len = ft_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		sign = -sign;
		nbr = -n;
		str[0] = '-';
	}
	else
		nbr = n;
	str = ft_char(str, nbr, len);
	return (str);
}
/*int	main(void)
{
	int	n = 75643;
	char	*str = ft_itoa(n);

	printf("Retour itoa de %d = char %s\n", n, str);
	free(str);
	return (0);
}*/
