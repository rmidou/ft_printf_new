/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmidou <rmidou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 08:16:19 by rmidou            #+#    #+#             */
/*   Updated: 2023/11/02 14:18:52 by rmidou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

static int	ft_putnbr_hexa_two(unsigned int nb, int upper, int j)
{
	int		i;
	int		len;
	char	*res;

	i = -1;
	len = ft_hexalen(nb);
	res = (char *)ft_calloc(sizeof(char), (len + 2));
	if (!res)
	{
		return (0);
	}
	while (nb != 0)
	{
		res[len--] = "0123456789abcdef"[nb % 16];
		nb = nb / 16;
		j++;
	}
	while (upper == 1 && res[++i])
		res[i] = ft_toupper(res[i]);
	ft_putstr(res);
	free (res);
	return (j);
}

int	ft_putnbr_hexa(unsigned int nb, int upper)
{
	int	j;

	j = 0;
	if (!nb)
	{
		ft_putstr("0");
		return (1);
	}
	return (ft_putnbr_hexa_two(nb, upper, j));
}
