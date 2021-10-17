/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:35:48 by layano            #+#    #+#             */
/*   Updated: 2021/10/13 19:09:01 by layano           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	const char		*source;

	if (!dst && !src)
		return (NULL);
	dest = dst;
	source = src;
	while (n--)
		*dest++ = *source++;
	return (dst);
}
