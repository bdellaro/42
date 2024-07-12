unsigned char	reverse_bits(unsigned char octet)
{
	int				bit = 8;
	unsigned char	res = 0;

	while (bit > 0)
	{
		res = res * 2 + (octet % 2);
		octet /= 2;
		bit--;
	}
	return (res);
}