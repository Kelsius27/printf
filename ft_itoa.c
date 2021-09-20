/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:11:01 by kmarques          #+#    #+#             */
/*   Updated: 2021/09/14 16:46:18 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sizenum(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		size++;
	}
	while (n >= 10)
	{
		size++;
		n = n / 10;
	}
	return (size + 1);
}

/**
 * @brief Transform int to char
 *
 * @param n Integer to be transformed
 * @return char* Pointer with number
 */
char	*ft_itoa(int n)
{
	char	*num;
	int		size;
	int		neg;

	neg = 1;
	size = ft_sizenum(n);
	num = malloc((size + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	*(num + size) = '\0';
	if (n < 0)
		neg = -1;
	while (size > 1)
	{
		size--;
		*(num + size) = neg * (n % 10) + '0';
		n = n / 10;
	}
	size--;
	if (neg == -1)
		*(num + size) = '-';
	else
		*(num + size) = (n % 10) + '0';
	return (num);
}
