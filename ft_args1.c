/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:50:59 by kmarques          #+#    #+#             */
/*   Updated: 2021/09/09 19:22:27 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treatchar(va_list args)
{
	unsigned char	c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_treatstring(va_list args)
{
	int	count;
	const char	*s;

	count = 0;
	s = va_arg(args, const char *);
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}
