/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:55:35 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/10 01:56:27 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	sa(t_stacks *stacks)
{
	swap(&(stacks->a));
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	swap(&(stacks->b));
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	swap(&(stacks->a));
	swap(&(stacks->b));
	ft_printf("ss\n");
}
