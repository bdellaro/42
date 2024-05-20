/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:41:56 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/20 15:40:21 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc <= 1)
		return (0);
	stack.a = NULL;
	stack.b = NULL;
	if (!ft_parse_args(argc, argv, &stack, &argv))
	{
		ft_free_all(&stack, argv, argc, 1);
		return (1);
	}
	if (!ft_check_duplicate(&stack))
	{
		ft_free_all(&stack, argv, argc, 1);
		return (1);
	}
	ft_sort_stack(&stack);
	ft_free_all(&stack, argv, argc, 0);
	return (0);
}
