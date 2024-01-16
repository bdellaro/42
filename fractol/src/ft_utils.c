/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:47:50 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/16 15:03:02 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

int	ft_mlx_error(t_mlx_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->win_ptr);
	free(data->mlx_ptr);
	ft_printf("Error : no window created\n");
	return (MLX_ERROR);
}

void	ft_mlx_free(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
