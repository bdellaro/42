/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:38:33 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/20 15:40:11 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_swap(t_list **stack)
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

void	ft_sa(t_stacks *stacks)
{
	ft_swap(&stacks->a);
	ft_printf("sa\n");
}

void	ft_sb(t_stacks *stacks)
{
	ft_swap(&stacks->b);
	ft_printf("sb\n");
}

void	ft_ss(t_stacks *stacks)
{
	ft_swap(&stacks->a);
	ft_swap(&stacks->b);
	ft_printf("ss\n");
}
