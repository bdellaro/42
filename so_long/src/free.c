/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:44:12 by bdellaro          #+#    #+#             */
/*   Updated: 2024/03/05 12:24:42 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

void	ft_free_path(t_solong *solong)
{
	int	i;

	i = -1;
	ft_free_visited(solong);
	ft_free_solong(solong);
	free(solong->data_map);
	while (solong->map.map[++i])
		free(solong->map.map[i]);
	free(solong->map.map);
	exit(EXIT_FAILURE);
}
