/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:33:42 by eboulajd          #+#    #+#             */
/*   Updated: 2025/12/09 17:59:44 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_decimal(int nbr)
{
	long	nb;
	int	i;
	int	written;

	i = 0;
	nb = nbr;
	if (nbr < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		nb = -nb;
		i++;
	}
	if (nb > 9)
	{
		written = ft_print_decimal(nb / 10);
		if (written < 0)
			return (-1);
		i += written;
		if (ft_print_char((nb % 10) + '0') < 0)
			return (-1);
		i++;
	}
	else
	{
		if (ft_print_char(nb + '0') < 0)
			return (-1);
		i++;
	}
	return (i);
}
