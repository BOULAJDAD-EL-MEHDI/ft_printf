/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <eboulajd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:07:56 by eboulajd          #+#    #+#             */
/*   Updated: 2025/12/09 17:54:31 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_nomber(int nb)
{
	long	nbr;
	int	len;

	len = 0;
	nbr = nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		len++;
	}
	if (nbr > 9)
	{
		len += print_number(nbr / 10);
		len += print_char((nbr % 10) + '0');
	}
	else
		len += print_char(nbr + '0');
	return (len);
}

