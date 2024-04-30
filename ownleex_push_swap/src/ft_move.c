/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:10:59 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/04/30 00:52:31 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stacks *stacks, t_list **stack, \
t_list *cheapest_node, char stack_name)
{
	while (*stack != cheapest_node)
	{
		if (stack_name == 'a')
		{
			if (cheapest_node->above_median)
				ra(stacks);
			else
				rra(stacks);
		}
		else if (stack_name == 'b')
		{
			if (cheapest_node->above_median)
				rb(stacks);
			else
				rrb(stacks);
		}
	}
}

void	rev_rotate_booth(t_stacks *stacks, t_list *cheapest_node)
{
	while (stacks->b != cheapest_node->target_node && \
	stacks->a != cheapest_node)
	{
		rrr(stacks);
		if (stacks->a == cheapest_node)
			break ;
	}
}

void	rotate_booth(t_stacks *stacks, t_list *cheapest_node)
{
	while (stacks->b != cheapest_node->target_node && \
	stacks->a != cheapest_node)
	{
		rr(stacks);
		if (stacks->a == cheapest_node)
			break ;
	}
}

t_list	*get_cheapest(t_list *stack)
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

void	move_a_to_b(t_stacks *stacks)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(stacks->a);
	if (cheapest_node->above_median && \
	cheapest_node->target_node->above_median)
		rotate_booth(stacks, cheapest_node);
	else if (!(cheapest_node->above_median) && \
	!(cheapest_node->target_node->above_median))
		rev_rotate_booth(stacks, cheapest_node);
	prep_for_push(stacks, &stacks->a, cheapest_node, 'a');
	prep_for_push(stacks, &stacks->b, cheapest_node->target_node, 'b');
	pb(stacks);
}
