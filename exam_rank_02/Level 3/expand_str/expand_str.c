#include <unistd.h>

void	expand_str(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;		
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
		{
			while (*str == ' ' || *str == '\t')
				str++;
			if (*str)
				write(1, "   ", 3);
		}
		if (*str != ' ' && *str != '\t' && *str)
			write(1, str++, 1);
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}