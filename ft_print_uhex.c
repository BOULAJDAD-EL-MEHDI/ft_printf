/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:18:57 by eboulajd          #+#    #+#             */
/*   Updated: 2025/11/11 18:15:50 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	print_char(char m)
{
	return (write(1, &m, 1));
}

int	ft_print_uhex(unsigned int nbr)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (nbr >= 16)
		i += print_hex_low(nbr / 16);
	i += print_char(base[nbr % 16]);
	return (i);
}
