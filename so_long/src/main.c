#include "../include/so_long.h"

void	ft_first_init(char *path, char *upper, char **argv)
{
	t_solong	solong;

	solong.name = upper;
	ft_printf("Map chosen : \033[1;35m%s\033[0m\n\n", upper);
	if (ft_strncmp(argv[1], "./maps/", 8) == 0)
	{
		solong.name = argv[1];
		ft_solong_init(path, &solong);
	}
	else
		ft_solong_init(path, &solong);
	exit(EXIT_SUCCESS);
}

void	ft_error_print(char **argv)
{
	ft_printf("Invalid map name.\n");
	ft_printf("Please enter :\n====>   \033[1;35m%s", argv[0]);
	ft_printf("\033[0m and \033[1;35m./maps/*.ber\033[0m\n");
	ft_printf("Or chose between :\n", argv[0]);
	ft_printf("====>	\033[1;35m%s\033[0m and -> ", argv[0]);
	ft_printf("\033[1;35mSmall\033[0m", argv[0]);
	ft_printf("\n                      -> \033[1;35mBig\033[0m");
	ft_printf("\n                      -> \033[1;35mMedium\033[0m\n");
	exit (EXIT_FAILURE);
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

	if (ft_strnstr(argv[1], "./maps/", 8)
		&& ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		ft_first_init(argv[1], "USER MAP", argv);
	upper = ft_upper(argv[1]);
	if ((!ft_strncmp(upper, "SMALL", 5))
		&& (!ft_strncmp(upper, "SMALL", 6)) != 0)
		ft_first_init(SMALL, upper, argv);
	if ((!ft_strncmp(upper, "MEDIUM", 6))
		&& (!ft_strncmp(upper, "MEDIUM", 7)) != 0)
		ft_first_init(MEDIUM, upper, argv);
	if ((!ft_strncmp(upper, "BIG", 3))
		&& (!ft_strncmp(upper, "BIG", 4)) != 0)
		ft_first_init(BIG, upper, argv);
	else
		ft_error_print(argv);
	free(upper);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_map_check(argv);
	else
		ft_error_print(argv);
	return (0);
}
