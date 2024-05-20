/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:31:25 by bdellaro          #+#    #+#             */
/*   Updated: 2024/04/30 10:31:37 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int     main(void)
{
	t_list  *lst;
	t_list  *new_lst;

	lst = ft_lstnew("second");
	new_lst = ft_lstnew("first");
	ft_lstadd_front(&lst, new_lst);
	printf("Le premier element est %s\n", (char *)lst->content);
	printf("Le deuxieme element est %s\n", (char *)lst->next->content);
	return (0);
}
*/
