/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:42:08 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/30 09:36:59 by bdellaro         ###   ########.fr       */
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

t_list	*ft_find_min(t_list *stack)
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
