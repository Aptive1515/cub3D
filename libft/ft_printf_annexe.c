/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_annexe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:58:55 by tdelauna          #+#    #+#             */
/*   Updated: 2022/05/29 22:38:26 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_print(long int n, int fd)
{
	unsigned int	nbr;
	int				value;

	value = 0;
	if (n < 0)
	{
		value += ft_putchar_fd_print('-', fd);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr > 9)
	{
		value += ft_putnbr_fd_print(nbr / 10, fd);
		nbr = nbr % 10;
	}
	value += ft_putchar_fd_print(nbr + '0', fd);
	return (value);
}

int	ft_putnbr_base_print(unsigned int nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	int	value;

	i = 0;
	size_base = 0;
	value = 0;
	if (nbr == 0)
		return (ft_putchar_fd_print('0', 1));
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	while (--i >= 0)
		value += ft_putchar_fd_print(base[nbr_final[i]], 1);
	return (value);
}

int	ft_am(unsigned long nbr, char *base)
{
	int	size_base;
	int	nbr_final[100];
	int	i;
	int	value;

	i = 0;
	size_base = 0;
	value = 0;
	if (nbr == 0)
		return (ft_putstr_fd_print("0x0", 1));
	value += ft_putstr_fd_print("0x", 1);
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	while (--i >= 0)
		value += ft_putchar_fd_print(base[nbr_final[i]], 1);
	return (value);
}
