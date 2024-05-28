/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:53:57 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/28 10:54:01 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

t_list	*ft_find_max(t_list *stack)
{
	t_list	*max;
	t_list	*current;

	if (!stack)
		return (NULL);
	max = stack;
	current = stack->next;
	while (current != NULL)
	{
		if (*((int *)current->content) > *((int *)max->content))
			max = current;
		current = current->next;
	}
	return (max);
}

void	ft_sort_three(t_stacks *stacks)
{
	t_list	*max_node;

	max_node = ft_find_max(stacks->a);
	if (max_node == stacks->a)
		ft_ra(stacks);
	else if (max_node == stacks->a->next)
		ft_rra(stacks);
	if (*(int *)stacks->a->content > *(int *)stacks->a->next->content)
		ft_sa(stacks);
}

int	ft_count_elements(t_list *stack)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = stack;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	ft_is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_stack(t_stacks *stacks)
{
	if (!ft_is_sorted(stacks->a))
	{
		if (ft_count_elements(stacks->a) == 2)
			ft_sa(stacks);
		else if (ft_count_elements(stacks->a) == 3)
			ft_sort_three(stacks);
		else if (ft_count_elements(stacks->a) == 5)
			ft_sort_five(stacks);
		else
			ft_big_sort(stacks);
	}
}
