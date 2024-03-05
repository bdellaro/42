/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:41:18 by bdellaro          #+#    #+#             */
/*   Updated: 2023/11/15 15:54:04 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_ptr_count(uintptr_t num)
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

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');
		else
			ft_print_char(num - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned char *ptr)
{
	unsigned long	i;
	int				n_count;

	n_count = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = (unsigned long)ptr;
	if (i == 0)
		n_count += write(1, "0", 1);
	else
	{
		n_count += write(1, "0x", 2);
		ft_put_ptr(i);
		n_count += ft_ptr_count(i);
	}
	return (n_count);
}
