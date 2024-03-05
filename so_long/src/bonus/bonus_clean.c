/* ************************************************************************** */
/*	                                                                    */
/*	                                                :::      ::::::::   */
/*   bonus_clean.c                                      :+:      :+:    :+:   */
/*	                                            +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>	            +#+  +:+       +#+        */
/*	                                        +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:26:34 by bdellaro	  #+#    #+#             */
/*   Updated: 2024/03/05 12:32:23 by bdellaro         ###   ########.fr       */
/*	                                                                    */
/* ************************************************************************** */
#include "../include/so_long_bonus.h"

void	ft_clean_sup(t_solong *solong)
{
	solong->tex.tex_wall = NULL;
	solong->tex.tex_floor = NULL;
	solong->tex.tex_player = NULL;
	solong->tex.tex_collect = NULL;
	solong->tex.tex_exit = NULL;
	solong->tex.tex_enemy = NULL;
	solong->tex.tex_enemy_b = NULL;
	solong->tex.tex_collect_b = NULL;
	solong->tex.tex_player_a = NULL;
	solong->tex.tex_player_w = NULL;
	solong->tex.tex_player_s = NULL;
}
