/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:27:39 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/28 22:06:23 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_list *stack)
{
	long	cheapest_cost;
	t_list	*cheapest_node;

	cheapest_node = NULL;
	if (!stack)
		return ;
	cheapest_cost = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_cost)
		{
			cheapest_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void	cost_analysis(t_stacks *stacks)
{
	t_list	*current_a;
	int		len_a;
	int		len_b;

	current_a = stacks->a;
	len_a = count_elements(stacks->a);
	len_b = count_elements(stacks->b);
	while (current_a)
	{
		if (current_a->above_median)
			current_a->push_cost = current_a->index;
		else
			current_a->push_cost = len_a - current_a->index;
		if (current_a->target_node)
		{
			if (current_a->target_node->above_median)
				current_a->push_cost += current_a->target_node->index;
			else
				current_a->push_cost += len_b - current_a->target_node->index;
		}
		current_a = current_a->next;
	}
}

void	set_target(t_stacks *stacks)
{
	t_list	*current_a;
	t_list	*current_b;
	long	best_index;

	current_a = stacks->a;
	while (current_a)
	{
		best_index = INT_MIN;
		current_b = stacks->b;
		while (current_b)
		{
			if (*(int *)current_b->content < *(int *)current_a->content && \
			*(int *)current_b->content > best_index)
			{
				best_index = *(int *)current_b->content;
				current_a->target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == INT_MIN)
			current_a->target_node = find_max(stacks->b);
		current_a = current_a->next;
	}
}

void	set_index_median(t_list *stack)
{
	t_list	*current;
	int		i;
	int		median;

	current = stack;
	i = 0;
	if (!stack)
		return ;
	median = count_elements(stack) / 2;
	while (current)
	{
		current->index = i;
		current->above_median = i <= median;
		current = current->next;
		i++;
	}
}

void	init_nodes(t_stacks *stacks)
{
	set_index_median(stacks->a);
	set_index_median(stacks->b);
	set_target(stacks);
	cost_analysis(stacks);
	set_cheapest(stacks->a);
}
