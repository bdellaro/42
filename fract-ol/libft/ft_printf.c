/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:58:01 by bdellaro          #+#    #+#             */
/*   Updated: 2023/11/15 17:28:39 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "include/ft_printf.h"

int	ft_format(va_list arg, const char format)
{
	int		n_count;

	n_count = 0;
	if (format == 'c')
		n_count += ft_print_char(va_arg(arg, int));
	else if (format == 's')
		n_count += ft_print_str(va_arg(arg, char *));
	else if (format == 'i' || format == 'd')
		n_count += ft_print_nbr(va_arg(arg, int));
	else if (format == 'p')
		n_count += ft_print_ptr((unsigned char *)va_arg(arg, void *));
	else if (format == 'u')
		n_count += ft_print_unsigned(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		n_count += ft_print_hexa(va_arg(arg, unsigned int), format);
	else if (format == '%')
		n_count += ft_print_percent();
	return (n_count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n_count;
	va_list	arg;

	i = 0;
	n_count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			n_count += ft_format(arg, str[i + 1]);
			i++;
		}
		else
			n_count += ft_print_char(str[i]);
		i++;
	}
	va_end(arg);
	return (n_count);
}
/*int	main(void)
{
//	char	test_c = "0";
//	char	*test_s = "Un test";
	int	test_i = 0;
	int 	test_d = 0;
	int 	test_u = 0;
//	unsigned long	test_x = 450;

//	printf("\nprintf de	test_c = %c\n", test_c);
//	ft_printf("ft_print de	test_c = %c\n/n", test_c);

//	printf("\nprintf de     test_s = %c\n", test_s);
//	ft_printf("ft_print de  test_s = %c\n/n", test_s);

	printf("\nprintf de     test_i = %c\n", test_i);
        ft_printf("ft_print de  test_i = %c\n/n", test_i);

	printf("\nprintf de     test_d = %c\n", test_d);
        ft_printf("ft_print de  test_d = %c\n/n", test_d);

	printf("\nprintf de     test_u = %c\n", test_u);
        ft_printf("ft_print de  test_u = %c\n/n", test_u);

//	printf("\nprintf de     test_p = %c\n", test_c);
//	ft_printf("ft_print de  test_p = %c\n/n", test_c);

//	printf("\nprintf de     test_x = %x\n", test_x);
//	ft_printf("ft_print de  test_x = %x\n/n", test_x);

	return (0);
}*/
