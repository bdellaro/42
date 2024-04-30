/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:29:49 by bdellaro          #+#    #+#             */
/*   Updated: 2024/04/30 10:30:33 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
/*
int     main(void)
{
	t_list	*lst;
	t_list	*new_lst;

	lst = ft_lstnew("first");
	new_lst = ft_lstnew("second");
	ft_lstadd_back(&lst, new_lst);
	printf("le dernier element est %s\n", (char *)lst->next->content);
	return (0);
}
*/
