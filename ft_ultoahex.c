/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoahex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:15:36 by kmarques          #+#    #+#             */
/*   Updated: 2021/09/20 20:38:51 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sizenum(unsigned int n)
{
	int	size;

	size = 0;
	while (n >= 16)
	{
		size++;
		n = n / 16;
	}
	return (size + 1);
}

/**
 * @brief Transform unsigned int to char hex
 *
 * @param n Unsigned integer to be transformed
 * @param c if x all lower if X all upper
 * @return char* Pointer with number hex
 */
char	*ft_ultoahex(unsigned long n, char c)
{
	char	*num;
	int		size;

	size = ft_sizenum(n);
	num = malloc((size + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	*(num + size) = '\0';
	while (size > 1)
	{
		size--;
		if ((n % 16) < 10)
			*(num + size) = (n % 16) + '0';
		else
			*(num + size) = (n % 16) + (c - 33);
		n = n / 16;
	}
	size--;
	if ((n % 16) < 10)
		*(num + size) = (n % 16) + '0';
	else
		*(num + size) = (n % 16) + (c - 33);
	return (num);
}
