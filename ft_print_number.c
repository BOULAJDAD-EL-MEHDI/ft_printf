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
	int	written;

	len = 0;
	nbr = nb;
	if (nbr < 0)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		nbr = -nbr;
		len++;
	}
	if (nbr > 9)
	{
		written = ft_print_nomber(nbr / 10);
		if (written < 0)
			return (-1);
		len += written;
		if (ft_print_char((nbr % 10) + '0') < 0)
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

