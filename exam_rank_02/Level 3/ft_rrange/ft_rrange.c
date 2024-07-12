#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int		i = 0;
	int		len = ((end > start) ? (end - start) : (start - end));
	int		*array = (int *)malloc(sizeof(int ) * (len + 1));

	if (end >= start)
		while (end >= start)
			array[i++] = end--;
	else
		while (end <= start)
			array[i++] = end++;
	return (array);
}