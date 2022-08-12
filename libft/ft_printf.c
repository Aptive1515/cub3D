/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:55:04 by tdelauna          #+#    #+#             */
/*   Updated: 2022/03/31 17:06:54 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		value;
	int		i;

	value = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			value += ft_parse(format[i + 1], args);
			i += 2;
		}
		else
			value += ft_putchar_fd_print(format[i++], 1);
	}
	va_end(args);
	return (value);
}

int	ft_parse(char format, va_list args)
{
	int			value;

	value = 0;
	if (format == 'c')
		value += ft_putchar_fd_print(va_arg(args, int), 1);
	else if (format == 's')
		value += ft_arg_str(va_arg(args, char *));
	else if (format == 'i' || format == 'd')
		value += ft_putnbr_fd_print(va_arg(args, int), 1);
	else if (format == 'u')
		value += ft_arg_unsigned(va_arg(args, int));
	else if (format == 'x')
		value += ft_putnbr_base_print(va_arg(args, int), "0123456789abcdef");
	else if (format == 'X')
		value += ft_putnbr_base_print(va_arg(args, int), "0123456789ABCDEF");
	else if (format == 'p')
		value += ft_am(va_arg(args, unsigned long), "0123456789abcdef");
	else if (format == '%')
		value += ft_putchar_fd_print('%', 1);
	else
		value += ft_putchar_fd_print(format, 1);
	return (value);
}

int	ft_arg_str(char *str)
{
	int	value;

	value = 0;
	if (str)
		value += ft_putstr_fd_print(str, 1);
	else
		value += ft_putstr_fd_print("(null)", 1);
	return (value);
}

int	ft_arg_unsigned(long int nbr)
{
	int	value;

	value = 0;
	if (nbr < 0)
	{
		nbr = 4294967296 + nbr;
		value += ft_putnbr_fd_print((nbr), 1);
	}
	else
		value += ft_putnbr_fd_print(nbr, 1);
	return (value);
}
