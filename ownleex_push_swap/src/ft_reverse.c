/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:33:00 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/29 14:35:45 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//The last element becomes the first one
void	reverse_rotate(t_list **stack)
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

void	rra(t_stacks *stacks)
{
	reverse_rotate(&(stacks->a));
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(&(stacks->b));
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(&(stacks->a));
	reverse_rotate(&(stacks->b));
	ft_printf("rrr\n");
}
