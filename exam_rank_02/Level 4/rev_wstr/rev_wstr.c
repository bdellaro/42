#include <unistd.h>

void	rev_wstr(char *str)
{
	int		start		= 0;
	int		end			= 0;
	int		is_first	= 1;

	while (str[end])
		end++;
	end--;
	while (end >= 0)
	{
		if (is_first == 0)
			write(1, " ", 1);
		is_first = 0;
		while (end >= 0 && (str[end] == ' ' || str[end] == '\t'))
			end--;
		start = end;
		while (start >= 0 && (str[start] != ' ' && str[start] != '\t'))
			start--;
		write(1, &str[start + 1], end - start);
		end = start;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}

