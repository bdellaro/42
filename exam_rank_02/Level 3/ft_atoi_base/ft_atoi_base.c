#include <stdio.h>

int	is_valid_char(char c, int base)
{
	char	*n1 = "0123456789abcdef";
	char	*n2 = "0123456789ABCDEF";

	while (base--)
		if (c == n1[base] || c == n2[base])
			return (1);
	return (0);
}

int	value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int		result = 0;
	int		sign = (*str == '-') ? -1 : 1;

	(*str == '-' || *str == '+') ? str++ : 0;
	while (is_valid_char(*str, str_base))
		result =  result * str_base + value(*str++);
	return (result * sign);
}
/*
int	main()
{
	int nbr = ft_atoi_base("13268!", 16);
	printf("%d\n", nbr);
	return (0);
}
*/