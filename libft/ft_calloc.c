/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:04:55 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/04 11:22:51 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*mem;
	size_t		i;

	i = nmemb * size;
	if (i / size != nmemb)
		return (NULL);
	mem = malloc(i);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, i);
	return (mem);
}
