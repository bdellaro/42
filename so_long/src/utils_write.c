#include "../include/so_long.h"

void	ft_write(t_solong *solong)
{
	if (solong->content.count_c >= 0)
	{
		ft_printf("Dimensions   : \033[1;37m%d * %d\033[0m\n" \
		, solong->width, solong->height);
		ft_printf("Collectables : \033[1;37m%d\033[0m\n\n" \
		, solong->content.count_c);
	}
}

void	ft_r(void)
{
	int	write_error;

	write_error = write(1, "\r", 1);
	(void)write_error;
}

void	ft_print_map_error(t_solong *solong, int fd)
{
	ft_printf("\n");
	if (solong->height == 0 || solong->total_length == 0)
	{
		ft_printf("Error\nEmpty map\n");
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (solong->height == solong->width)
	{
		ft_printf("Error\nMap is not rectangular");
		ft_free_solong(solong);
		exit(EXIT_FAILURE);
	}
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_error_image(char *texture)
{
	ft_printf("Error\nUnable to load texture --> %s\n", texture);
	exit(EXIT_FAILURE);
}
