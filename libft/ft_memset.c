/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:14:04 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:14:05 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*dest;

	dest = (unsigned char *)b;
	while (len--)
		*dest++ = (unsigned char)c;
	return (b);
}
