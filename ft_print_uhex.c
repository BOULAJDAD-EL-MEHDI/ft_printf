/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:18:57 by eboulajd          #+#    #+#             */
/*   Updated: 2025/12/09 17:56:43 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
