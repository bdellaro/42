/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:53:54 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/28 10:53:55 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	ft_get_position(t_list *stack, t_list *target)
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

void	ft_sort_two(t_stacks *stacks, char stack_name)
{
	if (stack_name == 'a' && *(int *)stacks->a->content > \
	*(int *)stacks->a->next->content)
		ft_sa(stacks);
	else if (stack_name == 'b' && *(int *)stacks->b->content < \
	*(int *)stacks->b->next->content)
		ft_sb(stacks);
}

void	ft_push_two_smallest_to_b(t_stacks *stacks)
{
	int		i;
	int		size;
	t_list	*min_node;

	size = ft_count_elements(stacks->a);
	i = 0;
	while (i < 2)
	{
		min_node = ft_find_min(stacks->a);
		while (stacks->a != min_node)
		{
			if (ft_get_position(stacks->a, min_node) < size / 2)
				ft_ra(stacks);
			else
				ft_rra(stacks);
		}
		ft_pb(stacks);
		i++;
	}
}

void	ft_sort_five(t_stacks *stacks)
{
	ft_push_two_smallest_to_b(stacks);
	ft_sort_three(stacks);
	ft_sort_two(stacks, 'b');
	ft_pa(stacks);
	ft_pa(stacks);
}
