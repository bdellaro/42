/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:38:29 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/20 15:40:09 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		*stack = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	ft_ra(t_stacks *stacks)
{
	ft_rotate(&stacks->a);
	ft_printf("ra\n");
}

void	ft_rb(t_stacks *stacks)
{
	ft_rotate(&stacks->b);
	ft_printf("rb\n");
}

void	ft_rr(t_stacks *stacks)
{
	ft_rotate(&stacks->a);
	ft_rotate(&stacks->b);
	ft_printf("rr\n");
}
