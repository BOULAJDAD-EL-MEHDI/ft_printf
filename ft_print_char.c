/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:09:01 by eboulajd          #+#    #+#             */
/*   Updated: 2025/11/10 11:48:08 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>

int	print_char(char m)
{
	return (write(1, &m , 1));
}

int	main()
{
	int	i;

	i = print_char("");
	printf("%d\n", i);
	i = print_char("%c", "");
	printf("%d\n", i);
	return 0;
}
