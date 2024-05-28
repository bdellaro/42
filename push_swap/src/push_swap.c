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

int	ft_check_duplicate(t_stacks *stacks)
{
	t_list	*current;
	t_list	*compare;

	current = stacks->a;
	while (current != NULL)
	{
		compare = current->next;
		while (compare != NULL)
		{
			if (*(int *)current->content == *(int *)compare->content)
				return (0);
			compare = compare->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_free_all(t_stacks *stacks, char **args, int argc, int error)
{
	int		i;

	if (argc == 2)
	{
		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);
	if (error)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_args(int argc, char **argv, t_stacks *stacks, char ***args)
{
	int		i;
	long	*value;

	ft_check_argc(argc, argv, args);
	i = -1;
	while ((*args)[++i])
	{
		if (!ft_is_number((*args)[i]))
		{
			ft_putstr_fd("Error\nArgument is not a number\n", 2);
			return (0);
		}
		value = malloc(sizeof(long));
		if (!value)
			return (0);
		*value = ft_atol((*args)[i]);
		if (*value > INT_MAX || *value < INT_MIN)
		{
			free(value);
			ft_putstr_fd("Error\nExceed integer value\n", 2);
			return (0);
		}
		ft_lstadd_back(&(stacks->a), ft_lstnew(value));
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**args;

	if (argc <= 2)
	{
		ft_putstr_fd("Error\nArgument missing\n", 2);
		return (0);
	}
	stacks.a = NULL;
	stacks.b = NULL;
	args = NULL;
	if (!ft_parse_args(argc, argv, &stacks, &args))
	{
		ft_free_all(&stacks, args, argc, 0);
		return (1);
	}
	if (!ft_check_duplicate(&stacks))
	{
		ft_free_all(&stacks, args, argc, 1);
		ft_putstr_fd("Duplicated number found\n", 2);
		return (1);
	}
	ft_sort_stack(&stacks);
	ft_free_all(&stacks, args, argc, 0);
	return (0);
}
