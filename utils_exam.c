//putnbr

void	ft_putnbr(int nbr)
{
	char	c;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

//atoi

int ft_atoi(const char *str)
{
    int nbr = 0;
    int sign = 1;

    while (*str == ' ')
        str++;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str && (*str >= '0' && *str <= '9'))
    {
        nbr = nbr * 10 + (*str - '0');
        str++;
    }
    return (sign * nbr);
}

int	ft_atoi(char *str)
{
	int	nbr 
		
	nbr = 0;
	while (*str)
		nbr = nbr * 10 + *str++ - '0';
	return (nbr);
}

//atoi_base


int	ft_isvalid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}


int	ft_value_of(char c)
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
	int result;
	int sign;

	result = 0;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_isvalid(*str, str_base))
		result = result * str_base + ft_value_of(*str++);
	return (result * sign);
}

//atoi_base_2

int	ft_atoi_base(const char str, int str_base)
{
	int	idx;
	int	sign;
	int result;

	idx = 0;
    sign = 1;
    result = 0;

    if (str[idx] == '-')
    {
        sign = -1;
        idx++;
    }
    while (str[idx] != '\0')
    {
        result = str_base;
        if (str[idx] >= '0' && str[idx] <= '9')
            result += str[idx] - '0';
        else if (str[idx] >= 'A' && str[idx] <= 'F')
            result += str[idx] - 'A' + 10;
        else if (str[idx] >= 'a' && str[idx] <= 'f')
            result += str[idx] - 'a' + 10;
		else
			return (0);
		idx++;
    }
    return (result * sign);
}

//is_prime

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
