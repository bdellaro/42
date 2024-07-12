#include <unistd.h>

void	rostring(char *str)
{
	int		i = 0;
	int		start = 0;
	int		end = 0;

	while (str[start] == ' ' || str[start] == '\t')
		start++;
	end = start;
	while (str[end] && (str[end] != ' ' && str[end] != '\t'))
		end++;
	i = end;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i])
	{
		while (str[i])
		{
			if (str[i] == ' ' || str[i] == '\t')
			{
				while (str[i] == ' ' || str[i] == '\t')
					i++;
				if (str[i])
					write(1, " ", 1);
			}
			else
				write(1, &str[i++], 1);
		}
		write(1, " ", 1);
	}
	write(1, &str[start], end - start);

}

int		main(int argc, char **argv)
{
	if (argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}