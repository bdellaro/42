/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdellaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:07:14 by bdellaro          #+#    #+#             */
/*   Updated: 2024/01/12 15:57:36 by bdellaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

int		ft_printf(const char *str, ...);
int		ft_print_nbr(int n);
int		ft_print_str(char *c);
int		ft_print_char(char c);
int		ft_print_hexa(unsigned int num, const char format);
int		ft_print_ptr(unsigned char *ptr);
int		ft_print_unsigned(unsigned int n);
int		ft_print_percent(void);

#endif
