/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/31 14:18:05 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/31 14:18:48 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;

	if (s == NULL)
		return (NULL);
	tmp = (unsigned char *)s;
	while (n--)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		++tmp;
	}
	return (NULL);
}
