/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:59:52 by eboulajd          #+#    #+#             */
/*   Updated: 2025/11/11 18:10:00 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	print_char(char m)
{
	return (write(1, &m, 1));
}

int	ft_print_lhex(unsigned int nbr)
{
	int	i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		i += print_hex_low(nbr / 16);
	i += print_char(base[nbr % 16]);
	return (i);
}

int main()
{
	int	i;

	i = print_hex_low(123456789);
	printf("  ==>  %d\n", i);
	i = printf("%x", 123456789);
	printf("  ==>  %d\n", i);
	i = print_hex_low(-1);
	printf("  ==>  %d\n", i);
	i = printf("%x", -1);
	printf("  ==>  %d\n", i);
	i = print_hex_low(255);
	printf("  ==>  %d\n", i);
	i = printf("%x", 255);
	printf("  ==>  %d\n", i);
	i = print_hex_low(18446744073709551615);
	printf("  ==>  %d\n", i);
	i = printf("%x", 18446744073709551615);
        printf("  ==>  %d\n", i);
	return 0;
}
