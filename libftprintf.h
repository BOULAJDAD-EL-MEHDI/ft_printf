/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:00:33 by eboulajd          #+#    #+#             */
/*   Updated: 2025/12/09 17:57:51 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

size_t	ft_strlen(char *str);
int	ft_print_char(char m);
int	ft_print_lhex(unsigned int nbr);
int	ft_print_decimal(int nbr);
int	ft_print_uhex(unsigned int nbr);
int	ft_print_nomber(int nb);
int	ft_print_pointer(void *val);
int	ft_print_string(char *str);

int	ft_printf(const char *format, ...);
int	print_unsigned_decimal(unsigned int nbr);

#endif
