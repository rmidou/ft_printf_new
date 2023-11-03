/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmidou <rmidou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:57:23 by rmidou            #+#    #+#             */
/*   Updated: 2023/11/02 14:25:07 by rmidou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_ulen(unsigned int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len = len * 10;
		n = n / 10;
	}
	return (len);
}

int	ft_hexalen(unsigned long int n)
{
	int	len;

	len = 0;
	while (n / 16 != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}
