/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:42:20 by bdellaro          #+#    #+#             */
/*   Updated: 2023/11/09 10:03:03 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexa_len(unsigned int num)
{
	int	n_count;

	n_count = 0;
	while (num != 0)
	{
		n_count++;
		num = num / 16;
	}
	return (n_count);
}

void	ft_put_hexa(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hexa(num / 16, format);
		ft_put_hexa(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');
		else
		{
			if (format == 'x')
				ft_print_char(num - 10 + 'a');
			if (format == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
}

int	ft_print_hexa(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hexa(num, format);
	return (ft_hexa_len(num));
}
