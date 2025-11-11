/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:33:57 by eboulajd          #+#    #+#             */
/*   Updated: 2025/11/11 12:18:22 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	print_char(char m)
{
	return (write(1, &m, 1));
}

int	print_unsigned_decimal(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += print_unsigned_decimal(nbr / 10);
		len += print_char((nbr % 10) + '0');
	}
	else
		len += print_char(nbr + '0');
	return (len);
}

int	main()
{
	int	i;

	i = print_unsigned_decimal(2147483648);
	printf(" ==> %d\n", i);
	i = printf("%u", 2147483648);
	printf(" ==> %d\n", i);
	i = print_unsigned_decimal(-1);
	printf(" ==> %d\n", i);
	i = printf("%u", -1);
        printf(" ==> %d\n", i);
	i = print_unsigned_decimal(4294967295);
	printf(" ==> %d\n", i);
	i = printf("%u", 4294967295);
	printf(" ==> %d\n", i);
	return 0;
}
