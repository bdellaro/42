/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:38:27 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/20 15:40:06 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	if (before_last)
		before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rra(t_stack *stack)
{
	ft_reverse_rotate(&stack->a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack *stack)
{
	ft_reverse_rotate(&stack->b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack *stack)
{
	ft_reverse_rotate(&stack->a);
	ft_reverse_rotate(&stack->b);
	ft_printf("rrr\n");
}
