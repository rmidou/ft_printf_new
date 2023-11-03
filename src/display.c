/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmidou <rmidou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:18:20 by rmidou            #+#    #+#             */
/*   Updated: 2023/11/02 14:25:04 by rmidou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbru(unsigned int nb)
{
	unsigned int	len;
	char			res;
	int				j;

	j = 0;
	len = ft_ulen(nb);
	while (len >= 1)
	{
		res = nb / len + '0';
		write (1, &res, 1);
		nb = nb % len;
		len = len / 10;
		j++;
	}
	return (j);
}

int	ft_putptr_two(unsigned long int nb, int j)
{
	int		len;
	char	*res;

	len = ft_hexalen(nb);
	res = (char *)ft_calloc(sizeof(char), (len + 2));
	if (!res)
		return (0);
	while (nb != 0)
	{
		res[len--] = "0123456789abcdef"[nb % 16];
		nb = nb / 16;
		j++;
	}
	ft_putstr(res);
	free (res);
	return (j);
}

int	ft_putptr(unsigned long int nb)
{
	int	j;

	j = 0;
	if (!nb)
	{
		ft_putstr("(nil)");
		return (5);
	}
	j = 2;
	ft_putstr("0x");
	return (ft_putptr_two(nb, j));
}
