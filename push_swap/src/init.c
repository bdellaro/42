/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:53:41 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/28 10:53:42 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_set_cheapest(t_list *stack)
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

void	ft_cost_analysis(t_stacks *stacks)
{
	t_list	*current_a;
	int		len_a;
	int		len_b;

	current_a = stacks->a;
	len_a = ft_count_elements(stacks->a);
	len_b = ft_count_elements(stacks->b);
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

void	ft_set_target(t_stacks *stacks)
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
			current_a->target_node = ft_find_max(stacks->b);
		current_a = current_a->next;
	}
}

void	ft_set_index_median(t_list *stack)
{
	t_list	*current;
	int		i;
	int		median;

	current = stack;
	i = 0;
	if (!stack)
		return ;
	median = ft_count_elements(stack) / 2;
	while (current)
	{
		current->index = i;
		current->above_median = i <= median;
		current = current->next;
		i++;
	}
}

void	ft_init_nodes(t_stacks *stacks)
{
	ft_set_index_median(stacks->a);
	ft_set_index_median(stacks->b);
	ft_set_target(stacks);
	ft_cost_analysis(stacks);
	ft_set_cheapest(stacks->a);
}
