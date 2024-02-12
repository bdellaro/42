/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:41:15 by bdellaro          #+#    #+#             */
/*   Updated: 2023/10/24 12:56:53 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t n)
{
	void	*ret;

	ret = malloc(n * nmemb);
	if (!ret)
		return (0);
	ft_bzero(ret, n * nmemb);
	return (ret);
}
