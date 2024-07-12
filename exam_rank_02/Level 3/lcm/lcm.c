unsigned int    lcm(unsigned int a, unsigned int b)
{
	int		lcm = (a >= b) ? a : b;

	if (a == 0 || b == 0)
		return (0);
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}
}