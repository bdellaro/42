/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:49:26 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/25 02:40:26 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->index = 0;
	new->push_cost = 0;
	new->above_median = false;
	new->cheapest = false;
	new->target_node = NULL;
	return (new);
}

/*
int	main(void)
{
	char	*str;
	t_list	*list;

	str = "bonjour";
	list = ft_lstnew(str);
	printf("%s\n", (char *)list->content);
	return (0);
}
*/
