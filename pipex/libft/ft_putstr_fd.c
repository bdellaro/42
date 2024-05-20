/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:29:53 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/20 09:50:44 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *c, int fd)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		write(fd, &c[i], 1);
		i++;
	}
}
/*int main()
{
        char *c = "Testicule"; // == char c[] = "xxxxx";

        ft_putstr(c);
        
        return(0);
}*/
