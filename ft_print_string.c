/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulajd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 11:12:58 by eboulajd          #+#    #+#             */
/*   Updated: 2025/11/11 18:25:09 by eboulajd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_print_string(char *str)
{
	int	i;
	int	len;

	if (!str)
		return (0);
	len = str_len(str);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	main()
{
	int	i;

	i = print_string(NULL);
	printf("\nreturn value is : %d", i);
	return 1;
}
