#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((octet & (0x01 << bit)))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		bit--;
	}
}