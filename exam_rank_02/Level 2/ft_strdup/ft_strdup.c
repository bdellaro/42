#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len = ft_strlen(src);
	char	*str = (char *)malloc(sizeof(char) * (len +1));
	int		i = 0;

	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}