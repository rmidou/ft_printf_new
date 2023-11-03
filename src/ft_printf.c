/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:24:10 by rmidou            #+#    #+#             */
/*   Updated: 2023/11/03 15:49:23 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_args_two(char const c, va_list *args)
{
	int	i;
	int	j;

	i = -2;
	j = 0;
	if (c == 'c')
	{
		i++;
		ft_putchar(va_arg(*args, int));
	}
	else if (c == 's')
		i += ft_putstr(va_arg(*args, char *));
	else if (c == 'd' || c == 'i')
	{
		j = va_arg(*args, int);
		ft_putnbr_fd(j, 1);
		i += ft_len(j);
	}
	else if (c == 'u')
		i += ft_putnbru(va_arg(*args, unsigned int));
	return (i);
}

static int	ft_print_args(char const c, va_list *args)
{
	int	i;

	i = -2;
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u')
		return (ft_print_args_two(c, args));
	else if (c == '%')
		i += ft_putchar('%');
	else if (c == 'p')
		i += ft_putptr((long int)va_arg(*args, void *));
	else if (c == 'x')
		i += ft_putnbr_hexa(va_arg(*args, long int), 0);
	else if (c == 'X')
		i += ft_putnbr_hexa(va_arg(*args, long int), 1);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			write(1, &s[i], 1);
		else
		{
			count += ft_print_args(s[i + 1], &args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (i + count);
}
