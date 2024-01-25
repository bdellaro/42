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
#include "../include/so_long.h"

void	ft_mlx_exit(t_solong *solong)
{
	mlx_destroy_window(solong->mlx_ptr, solong->win_ptr);
	mlx_destroy_display(solong->mlx_ptr);
	free(solong->mlx_ptr);
	exit(EXIT_SUCCESS);
}
