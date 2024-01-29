/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:53:07 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/25 18:09:54 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_solong	solong;
	solong.name = argv[1];
	if (argc == 2)
		ft_solong_init(&solong);
	else
	{
		ft_printf("Invalid argument(s).\n");
		ft_printf("Please enter a color as paramater.\n");
		exit (EXIT_FAILURE);
	}
	return (0);
}
