/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:30:41 by eboulajd          #+#    #+#             */
/*   Updated: 2025/11/11 18:19:30 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>

int	print_char(char m)
{
	return (write(1, &m, 1));
}

int	print_hex(unsigned long nbr)
{
	int	i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		i += print_hex(nbr / 16);
	i += print_char(base[nbr % 16]);
	return (i);
}

int	ft_print_pointer(void *val)
{
	int	i;
	unsigned long	addr;

	addr = (unsigned long)val;
	i = 0;
	if (addr == 0)
	{
		i += write(1, "(nil)", 5);
		return (i);
	}
	else
	{
		write(1, "0x", 2);
		i += print_hex(addr);
	}
	return (i);
}

int	main()
{
	int	i = 42;
	int	*p = &i;
	int	j;
	int	**q = &p;
	j = print_pointer(p);
	printf("   =======   %d\n", j);
	j = printf("%p", p);
	printf("   =======   %d\n", j);
	j = print_pointer(q);
	printf("   =======   %d\n", j); 
	j = printf("%p", q);
	printf("   =======   %d\n", j);

	return 0;
}
