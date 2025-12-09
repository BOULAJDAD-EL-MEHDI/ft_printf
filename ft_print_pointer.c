/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:30:41 by eboulajd          #+#    #+#             */
/*   Updated: 2025/12/09 17:55:54 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_pointer(void *val)
{
	int	i;
	unsigned long	addr;

	addr = (unsigned long)val;
	i = 0;
	if (addr == 0)
	{
		i += write(1, "(nil)", 5);
		return (i);
	}
	else
	{
		write(1, "0x", 2);
		i += print_hex(addr);
	}
	return (i);
}
