/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:44:56 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/04/24 21:27:55 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_list *stack, t_list *target)
{
	int	pos;

	pos = 0;
	while (stack != NULL)
	{
		if (stack == target)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	sort_two(t_stacks *stacks, char stack_name)
{
	if (stack_name == 'a' && *(int *)stacks->a->content > \
	*(int *)stacks->a->next->content)
		sa(stacks);
	else if (stack_name == 'b' && *(int *)stacks->b->content < \
	*(int *)stacks->b->next->content)
		sb(stacks);
}

void	push_two_smallest_to_b(t_stacks *stacks)
{
	int		i;
	int		size;
	t_list	*min_node;

	size = count_elements(stacks->a);
	i = 0;
	while (i < 2)
	{
		min_node = find_min(stacks->a);
		while (stacks->a != min_node)
		{
			if (get_position(stacks->a, min_node) < size / 2)
				ra(stacks);
			else
				rra(stacks);
		}
		pb(stacks);
		i++;
	}
}

void	sort_five(t_stacks *stacks)
{
	push_two_smallest_to_b(stacks);
	sort_three(stacks);
	sort_two(stacks, 'b');
	pa(stacks);
	pa(stacks);
}
