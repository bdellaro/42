/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:42:08 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/20 15:40:13 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_check_argc(int argc, char **argv, char ***args)
{
	if (argc == 2)
		*args = ft_split(argv[1], ' ');
	else
		*args = argv + 1;
}
