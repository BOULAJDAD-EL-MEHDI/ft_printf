/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 19:07:56 by eboulajd          #+#    #+#             */
/*   Updated: 2025/11/11 18:17:03 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	print_char(char m)
{
	return (write(1, &m, 1));
}

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

int	main()
{
	int	i;

	i = print_number(2147483647);
	printf("\n\n %d \n\n", i);
	i = printf("%d", 2147483647);
	printf("\n\n %d \n\n", i);
	i = print_number(-2147483648);
	printf("\n\n %d\n\n ", i);
	i = printf("%d", -2147483648);
	printf("\n\n %d\n\n ", i);
	return 0;
}
