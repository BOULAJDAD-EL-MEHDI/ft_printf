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

static int	print_hex(unsigned long addr)
{
	int	i;

	i = 0;
	if (addr >= 16)
		i += print_hex(addr / 16);
	if (i < 0 || ft_print_char("0123456789abcdef"[addr % 16]) < 0)
		return (-1);
	i++;
	return (i);
}

int	ft_print_pointer(void *val)
{
	int	i;
	unsigned long	addr;

	addr = (unsigned long)val;
	i = 0;
	if (addr == 0)
	{
		i = write(1, "(nil)", 5);
		if (i != 5)
			return (-1);
		return (i);
	}
	else
	{
		if (write(1, "0x", 2) != 2)
			return (-1);
		i += print_hex(addr);
		if (i < 0)
			return (-1);
		i += 2;
	}
	return (i);
}
