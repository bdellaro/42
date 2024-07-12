#include <unistd.h>

void	last_word(char *str)
{
	while (*str)
		str++;
	str--;
	while ((*str == ' ' || *str == '\t') && *str)
		str--;
	while (*str != ' ' && *str != '\t' && *str)
		str--;
	str++;
	while (*str != ' ' && *str != '\t' && *str)
		write(1, str++, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}