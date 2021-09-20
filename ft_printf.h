/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:27:46 by kmarques          #+#    #+#             */
/*   Updated: 2021/09/20 20:38:16 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *, ...);
int		ft_treatstring(va_list args);
int		ft_treatchar(va_list args);
int		ft_treatint(va_list args);
int		ft_treatunsigint(va_list args);
int		ft_treathex(va_list args, char s);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_ultoahex(unsigned long n, char c);


#endif
