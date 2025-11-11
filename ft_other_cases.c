/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:25:27 by eboulajd          #+#    #+#             */
/*   Updated: 2025/11/11 18:29:13 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	print_char(char m)
{
	return (write(1, &m , 1));
}

int	ft_other_cases(char m)
{
	int	i;

	i = 0;
	i += write(1, "%", 1);
	i += ft_print_char(m);
	return (i);
}_
