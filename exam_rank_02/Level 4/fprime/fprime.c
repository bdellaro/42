#include <stdlib.h>
#include <stdio.h>

void	fprime(int nbr)
{
	int		i = 2;

	while (nbr >= i)
	{
		if (nbr % i == 0)
		{
			printf("%d", i);
			if (nbr == i)
				break;
			printf("*");
			nbr /= i;
			i = 1;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}