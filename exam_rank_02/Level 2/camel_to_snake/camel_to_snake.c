#include <unistd.h>

void	ft_camel_to_snake(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			*str += 32;
			write(1, "_", 1);
		}
		else
			write(1, str++, 1);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_camel_to_snake(argv[1]);
	write(1, "\n", 1);
	return (0);
}