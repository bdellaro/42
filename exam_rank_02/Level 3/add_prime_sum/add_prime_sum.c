#include <unistd.h>

int	ft_atoi(char *str)
{
	int		nbr = 0;
	
	while (*str)
		nbr = nbr * 10 + *str++ - '0';
	return (nbr);
}

int	is_prime(int nbr)
{
	int		i = 2;

	if (nbr <= 1)
		return (0);
	while (i * i <= nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int nbr)
{
	char	c;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int		nbr = ft_atoi(argv[1]);
		int		res = 0;
		while (nbr > 0)
		{
			if (is_prime(nbr))
				res += nbr;
			nbr--;
		}
		ft_putnbr(res);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}