/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:38:39 by bdellaro          #+#    #+#             */
/*   Updated: 2024/05/30 11:50:35 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_putnbr_hex(int nbr) {
    char *hex_digits = "0123456789abcdef";
    if (nbr >= 16) {
        ft_putnbr_hex(nbr / 16);
        ft_putnbr_hex(nbr % 16);
    } else {
        write(1, &hex_digits[nbr], 1);
    }
}

int ft_strlen(char *str) {
    int len = 0;
    while (*str++) {
        len++;
    }
    return len;
}

int ft_atoi(char *str)
{
    int nbr;

    nbr = 0;
    while (*str)
        nbr = nbr * 10 + *str++ - '0';
    return (nbr);
}

int main(int argc, char *argv[]) {
    int nbr;

    if (argc != 2) {
        write(1, "\n", 1);
        return 0;
    }

    nbr = ft_atoi(argv[1]);

    ft_putnbr_hex(nbr);
    write(1, "\n", 1);
    return 0;
}
