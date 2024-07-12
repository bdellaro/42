#include <unistd.h>

void	epur_str(char *str)
{
	int		i		= 0;
	int		len		= 0;

	while (str[len])
		len++;
	len--;
	while (str[len] == ' ' || str[len] == '\t')
		len--;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i] && i <= len)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			while ((str[i] == ' ' || str[i] == '\t') && i <= len)
				i++;
			if (str[i])
				write(1, " ", 1);
			
		}
		else
			write(1, &str[i++], 1);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}