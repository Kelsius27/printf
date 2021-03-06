/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:50:59 by kmarques          #+#    #+#             */
/*   Updated: 2021/09/21 16:27:22 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treatstring(va_list args)
{
	int			count;
	const char	*s;

	count = 0;
	s = va_arg(args, const char *);
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	return (count);
}

int	ft_treatint(va_list args)
{
	int			count;
	const char	*s;
	int			number;

	count = 0;
	number = va_arg(args, int);
	s = ft_itoa(number);
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	free((void *)(s - count));
	return (count);
}

int	ft_treatunsigint(va_list args)
{
	int				count;
	const char		*s;
	unsigned int	number;

	count = 0;
	number = va_arg(args, unsigned int);
	s = ft_utoa(number);
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	free((void *)(s - count));
	return (count);
}

int	ft_treathex(va_list args, char c)
{
	int				count;
	const char		*s;
	unsigned int	number;

	count = 0;
	number = va_arg(args, unsigned int);
	s = ft_ultoahex((unsigned long)number, c);
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	free((void *)(s - count));
	return (count);
}

int	ft_treatpointer(va_list args)
{
	int				count;
	const char		*s;
	unsigned long	str;

	write (1, "0x", 2);
	count = 2;
	str = va_arg(args, unsigned long);
	s = ft_ultoahex(str, 'x');
	while (*s)
	{
		write(1, s, 1);
		s++;
		count++;
	}
	free((void *)(s - (count - 2)));
	return (count);
}
