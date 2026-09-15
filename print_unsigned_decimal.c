/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:33:57 by eboulajd          #+#    #+#             */
/*   Updated: 2025/12/09 17:57:14 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_unsigned_decimal(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += print_unsigned_decimal(nbr / 10);
		if (len < 0 || ft_print_char((nbr % 10) + '0') < 0)
			return (-1);
		len++;
	}
	else
	{
		if (ft_print_char(nbr + '0') < 0)
			return (-1);
		len++;
	}
	return (len);
}
