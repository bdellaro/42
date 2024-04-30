/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:42:11 by bdellaro          #+#    #+#             */
/*   Updated: 2023/10/25 07:10:00 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
/*int main (void)
{
        printf("Test : 2147483647\n");
        ft_putnbr_fd(2147483647);

        printf("\nTest : -2147483648\n");
        ft_putnbr_fd(-2147483648);

        printf("\nTest : 0\n");
        ft_putnbr_fd(0);

        printf("\nTest : 1\n");
        ft_putnbr_fd(1);

        printf("\nTest : 42\n");
        ft_putnbr_fd(42);
        return (0);
}*/
