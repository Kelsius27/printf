/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:11:01 by kmarques          #+#    #+#             */
/*   Updated: 2021/09/20 18:31:22 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sizenum(unsigned int n)
{
	int	size;

	size = 0;
	while (n >= 10)
	{
		size++;
		n = n / 10;
	}
	return (size + 1);
}

/**
 * @brief Transform unsigned int to char
 *
 * @param n Unsigned integer to be transformed
 * @return char* Pointer with number
 */
char	*ft_utoa(unsigned int n)
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
		*(num + size) = (n % 10) + '0';
		n = n / 10;
	}
	size--;
	*(num + size) = (n % 10) + '0';
	return (num);
}
