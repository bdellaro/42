/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_path_sup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:09:46 by bdellaro          #+#    #+#             */
/*   Updated: 2024/02/29 18:10:07 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_key_a(t_solong *solong)
{
	solong->movement = 'a';
	solong->map.player_x--;
}

void	ft_key_d(t_solong *solong)
{
	solong->movement = 'd';
	solong->map.player_x++;
}
