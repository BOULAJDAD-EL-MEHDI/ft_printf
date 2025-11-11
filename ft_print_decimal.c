/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:33:42 by eboulajd          #+#    #+#             */
/*   Updated: 2025/11/11 18:13:34 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.c"
#include <unistd.h>
#include <stdio.h>

int	print_char(char m)
{
	return (write(1, &m, 1));
}

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

int	main()
{
	int	i;

	i = print_int(2147483648);
	printf("  ==  %d\n", i);
	i = printf("%d", 2147483648);
	printf("  ==  %d", i);
	return 0;
}
