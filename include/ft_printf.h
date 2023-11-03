/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmidou <rmidou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:08:56 by rmidou            #+#    #+#             */
/*   Updated: 2023/11/02 14:17:38 by rmidou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <libft.h>
# include <stdarg.h>

int				ft_putnbr_hexa(unsigned int nb, int upper);
int				ft_putstr(const char *s);
int				ft_putchar(const char c);
int				ft_putnbru(unsigned int nb);
int				ft_putptr_two(unsigned long int nb, int j);
int				ft_putptr(unsigned long int nb);
unsigned int	ft_ulen(unsigned int n);
int				ft_hexalen(unsigned long int n);
int				ft_len(int n);

#endif