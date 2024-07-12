#include <unistd.h>

int	ft_atoi(char *str)
{
	int	res;

	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = n % 10 + '0';
	write (1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i = 1;

	if (argc == 2)
	{
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(ft_atoi(argv[1]));
			write(1, " = ", 3);
			ft_putnbr(ft_atoi(argv[1]) * i);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}