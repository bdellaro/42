/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:53:45 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/28 10:53:46 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_prep_for_push(t_stacks *stacks, t_list **stack, \
t_list *cheapest_node, char stack_name)
{
	while (*stack != cheapest_node)
	{
		if (stack_name == 'a')
		{
			if (cheapest_node->above_median)
				ft_ra(stacks);
			else
				ft_rra(stacks);
		}
		else if (stack_name == 'b')
		{
			if (cheapest_node->above_median)
				ft_rb(stacks);
			else
				ft_rrb(stacks);
		}
	}
}

void	ft_rev_rotate_booth(t_stacks *stacks, t_list *cheapest_node)
{
	while (stacks->b != cheapest_node->target_node && \
	stacks->a != cheapest_node)
	{
		ft_rrr(stacks);
		if (stacks->a == cheapest_node)
			break ;
	}
}

void	ft_rotate_booth(t_stacks *stacks, t_list *cheapest_node)
{
	while (stacks->b != cheapest_node->target_node && \
	stacks->a != cheapest_node)
	{
		ft_rr(stacks);
		if (stacks->a == cheapest_node)
			break ;
	}
}

t_list	*ft_get_cheapest(t_list *stack)
{
	t_list	*current;
	t_list	*cheapest_node;

	current = stack;
	cheapest_node = NULL;
	while (current)
	{
		if (current->cheapest)
		{
			cheapest_node = current;
			break ;
		}
		current = current->next;
	}
	return (cheapest_node);
}

void	ft_move_a_to_b(t_stacks *stacks)
{
	t_list	*cheapest_node;

	cheapest_node = ft_get_cheapest(stacks->a);
	if (cheapest_node->above_median && \
	cheapest_node->target_node->above_median)
		ft_rotate_booth(stacks, cheapest_node);
	else if (!(cheapest_node->above_median) && \
	!(cheapest_node->target_node->above_median))
		ft_rev_rotate_booth(stacks, cheapest_node);
	ft_prep_for_push(stacks, &stacks->a, cheapest_node, 'a');
	ft_prep_for_push(stacks, &stacks->b, cheapest_node->target_node, 'b');
	ft_pb(stacks);
}
