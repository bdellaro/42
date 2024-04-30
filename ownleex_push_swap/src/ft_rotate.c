/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:30:02 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/28 23:11:37 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//The first element becomes the last one
void	rotate(t_list **stack)
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

void	ra(t_stacks *stacks)
{
	rotate(&(stacks->a));
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	rotate(&(stacks->b));
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	rotate(&(stacks->a));
	rotate(&(stacks->b));
	ft_printf("rr\n");
}
