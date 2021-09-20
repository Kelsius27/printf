/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 18:07:41 by kmarques          #+#    #+#             */
/*   Updated: 2021/09/20 18:52:15 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treatargs(const char *str, va_list args)
{
	int			count;

	count = 1;
	if (*str == 'c')
		count = ft_treatchar(args);
	if (*str == 's')
		count = ft_treatstring(args);
	//if (*str == 'p')
	if ((*str == 'd') || (*str == 'i'))
		count = ft_treatint(args);
	if (*str == 'u')
		count = ft_treatunsigint(args);
	if ((*str == 'x') || (*str == 'X'))
		count = ft_treathex(args, *str);
	if (*str == '%')
		write (1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_treatargs(str, args);
		}
		else
		{
			write(1, str, 1);
			count++;
		}
		str++;
	}
	va_end(args);
	return (count);
}
