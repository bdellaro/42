/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:53:51 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/30 09:33:28 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_min_on_top(t_stacks *stacks, t_list **a)
{
	t_list	*min_node;

	min_node = ft_find_min(*a);
	while (*a != min_node)
	{
		if (min_node->above_median)
			ft_ra(stacks);
		else
			ft_rra(stacks);
	}
}

void	ft_big_sort(t_stacks *stacks)
{
	int		len_a;

	len_a = ft_count_elements(stacks->a);
	ft_pb(stacks);
	while (--len_a)
	{
		ft_init_nodes(stacks);
		ft_move_a_to_b(stacks);
	}
	while (stacks->b)
		ft_pa(stacks);
	ft_set_index_median(stacks->a);
	ft_min_on_top(stacks, &stacks->a);
}
