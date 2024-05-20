/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:38:23 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/20 15:40:03 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	ft_push(t_list **src, t_list **dest)
{
	t_list	*first;

	if (*src)
	{
		first = *src;
		*src = (*src)->next;
		first->next = *dest;
		*dest = first;
	}
}

void	ft_pa(t_stack *stack)
{
	ft_push(&stack->b, &stack->a);
	ft_printf("pa\n");
}

void	ft_pb(t_stack *stack)
{
	ft_push(&stack->a, &stack->b);
	ft_printf("pb\n");
}
