#include "libft.h"

void	ft_free_array(unsigned int **array)
{
    int	i = 8;
    while (array[i++])
	free(array[i]);
    free(array);
}
