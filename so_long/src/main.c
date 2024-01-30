#include "../include/so_long.h"

void	ft_error_print(void)
{
                ft_printf("Invalid map name.\n");
                ft_printf("Please chose between :\n");
                ft_printf("====>    Small  <>  Big  <>  Medium\n");
		exit (EXIT_FAILURE);
}

char	*ft_upper(char *argv)
{
        char    *upper;
        int     i;

        upper = (char *)malloc((ft_strlen(argv) + 1) * sizeof(char));
        i = 0;
	while (argv[i])
        {
                upper[i] = ft_toupper(argv[i]);
                i++;
        }
        upper[i] = 0;
	return (upper);
}

void    ft_map_check(char **argv)
{
        t_solong        solong;
        char    *upper;

	upper = ft_upper(argv[1]);
	if (!ft_strncmp(upper, "SMALL", 5) && !ft_strncmp(upper, "SMALL",
        6) != 0)
        {
                solong.name = upper;
                ft_printf("Map chosen : %s\n", argv[1]);
                ft_solong_init(&solong);
        }
        else
		ft_error_print();	
	free(upper);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_map_check(argv);
	else
		ft_error_print();
	return (0);
}
