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

	i = 0;
	nb = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i++;
	}
	if (nb > 9)
	{
		i += print_int(nb / 10);
		i += print_char((nb % 10) + '0');
	}
	else
		i += print_char(nb + '0');
	return (i);
}
