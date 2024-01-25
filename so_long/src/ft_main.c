/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:53:07 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/18 17:51:06 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_color_check(char **argv)
{
	t_solong	solong;
	int	color;
	char	*upper;
	int	i;

	upper = (char *)malloc((ft_strlen(argv[1]) + 1) * sizeof(char));
	i = 0;
	while (argv[1][i])
	{
		upper[i] = ft_toupper(argv[1][i]);
		i++;
	}
	upper[i] = 0;
	color = -1;
	solong.name = upper;
	if (!ft_strncmp(upper, "RED", 3) && !ft_strncmp(upper, "RED",
	4))
		color = RED;
	else if (!ft_strncmp(upper, "GREEN", 5) && !ft_strncmp(upper,
	"GREEN", 6))
		color = GREEN;
	else if (!ft_strncmp(upper, "BLUE", 4) && !ft_strncmp(upper,
	"BLUE", 5))
		color = BLUE;
	else if (!ft_strncmp(upper, "MAGENTA", 7) && !ft_strncmp(upper,
	"MAGENTA", 8))
		color = MAGENTA_BURST;
	else if (!ft_strncmp(upper, "ORANGE", 6) && !ft_strncmp(upper,
	"ORANGE", 7))
		color = NEON_ORANGE;
	else if (!ft_strncmp(upper, "PINK", 4) && !ft_strncmp(upper, "PINK", 5))
		color = HOT_PINK;
	else if (!ft_strncmp(upper, "WHITE", 5) && !ft_strncmp(upper,
	"WHITE", 6))
		color = WHITE;
	else if (!ft_strncmp(upper, "BLACK", 5) && !ft_strncmp(upper, "BLACK", 6))
		color = BLACK;
	if (color != -1)
	{
		solong.color = color;
		ft_printf("Color chosen : %s\n", upper);
		ft_solong_init(&solong);
	}
	else
	{
		ft_printf("Invalid color name.\n");
		exit (EXIT_FAILURE);
	}
	free(upper);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_color_check(argv);
	else
	{
		ft_printf("Invalid argument(s).\n");
		ft_printf("Please enter a color as paramater.\n");
		exit (EXIT_FAILURE);
	}
	return (0);
}
