/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:25 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/28 22:19:51 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *stack)
{
	t_list	*min;
	t_list	*current;

	if (!stack)
		return (NULL);
	min = stack;
	current = stack->next;
	while (current)
	{
		if (*((int *)current->content) < *((int *)min->content))
			min = current;
		current = current->next;
	}
	return (min);
}

void	min_on_top(t_stacks *stacks, t_list **a)
{
	t_list	*min_node;

	min_node = find_min(*a);
	while (*a != min_node)
	{
		if (min_node->above_median)
			ra(stacks);
		else
			rra(stacks);
	}
}

void	big_sort(t_stacks *stacks)
{
	int		len_a;

	len_a = count_elements(stacks->a);
	pb(stacks);
	while (--len_a)
	{
		init_nodes(stacks);
		move_a_to_b(stacks);
	}
	while (stacks->b)
		pa(stacks);
	set_index_median(stacks->a);
	min_on_top(stacks, &stacks->a);
}
