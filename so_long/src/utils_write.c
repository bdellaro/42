/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:30:13 by bdellaro          #+#    #+#             */
/*   Updated: 2024/03/03 21:58:31 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
		ft_free_solong(solong);
		free(solong->data_map);
		close(fd);
		exit(EXIT_FAILURE);
	}
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	ft_error_image(char *texture, t_solong *solong)
{
	(void)solong;
	ft_printf("Error\nUnable to load texture --> %s\n", texture);
//	ft_delete_mlx(solong);
//	mlx_close_window(solong->mlx);
//	mlx_terminate(solong->mlx);
	free(solong->data_map);
//	ft_free_solong(solong);
	ft_free_2d(solong->map.map);
//	mlx_terminate(solong->mlx);
//	return ;
	exit(EXIT_FAILURE);
}
