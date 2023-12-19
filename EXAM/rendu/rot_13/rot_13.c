/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:59:31 by bdellaro          #+#    #+#             */
/*   Updated: 2023/12/19 15:52:09 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rot_13(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (str[i] >= 'a')
				str[i] = (str[i] - 'a' + 13) % 26 + 'a';
			else
				str[i] = (str[i] - 'A' + 13) % 26 + 'A';
		}
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_rot_13(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}
