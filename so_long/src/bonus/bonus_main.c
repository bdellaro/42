/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:10:53 by bdellaro          #+#    #+#             */
/*   Updated: 2024/03/05 10:22:02 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_first_init(char *path, char *upper, char **argv)
{
	t_solong	solong;

	solong.name = upper;
	ft_printf("Map chosen : \033[1;35m%s\033[0m\n\n", upper);
	if (ft_strnstr(argv[1], "maps/", 6)
		&& ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		ft_solong_init(path, &solong, 0);
	}
	else
		ft_solong_init(path, &solong, 1);
}

void	ft_error_print(char **argv)
{
	ft_printf("Invalid map name.\n");
	ft_printf("Please enter :\n====>   \033[1;35m%s", argv[0]);
	ft_printf("\033[0m and \033[1;35m  maps/*.ber\033[0m\n");
	ft_printf("Or chose between :\n", argv[0]);
	ft_printf("====>	\033[1;35m%s\033[0m and -> ", argv[0]);
	ft_printf("\033[1;35mSmall\033[0m", argv[0]);
	ft_printf("\n                      -> \033[1;35mBig\033[0m");
	ft_printf("\n                      -> \033[1;35mMedium\033[0m\n");
}

char	*ft_upper(char *argv)
{
	char	*upper;
	int		i;

	upper = (char *)malloc((ft_strlen(argv) + 1) * sizeof(char));
	if (!upper)
	{
		ft_printf("Error\nMemory allocation failed");
		free(upper);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[i])
	{
		upper[i] = ft_toupper(argv[i]);
		i++;
	}
	upper[i] = 0;
	return (upper);
}

void	ft_map_check(char **argv)
{
	char	*upper;

	if (ft_strnstr(argv[1], "maps/", 6)
		&& ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		ft_first_init(argv[1], "USER MAP", argv);
	upper = ft_upper(argv[1]);
	if ((!ft_strncmp(upper, "SMALL", 5))
		&& (!ft_strncmp(upper, "SMALL", 6)) != 0)
		ft_first_init(SMALL_B, upper, argv);
	if ((!ft_strncmp(upper, "MEDIUM", 6))
		&& (!ft_strncmp(upper, "MEDIUM", 7)) != 0)
		ft_first_init(MEDIUM_B, upper, argv);
	if ((!ft_strncmp(upper, "BIG", 3))
		&& (!ft_strncmp(upper, "BIG", 4)) != 0)
		ft_first_init(BIG_B, upper, argv);
	else
	{
		ft_error_print(argv);
		free(upper);
	}
}

int	main(int argc, char **argv)
{
	t_solong	solong;

	ft_bzero(&solong, sizeof(t_solong));
	if (argc == 2)
		ft_map_check(argv);
	else
		ft_error_print(argv);
	return (0);
}
