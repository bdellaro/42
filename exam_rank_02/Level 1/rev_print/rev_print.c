#include <unistd.h>

void	rev_print(char *str)
{
	while (*str)
		str++;
	str--;
	while (*str)
		write(1, str--, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rev_print(argv[1]);
	write(1, "\n", 1);
	return (0);
}