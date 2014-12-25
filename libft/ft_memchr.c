/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:13:14 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:13:28 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	char		*str;

	str = (char *)s;
	while (n)
	{
		if (*str == (char)c)
			return (str);
		str++;
		n--;
	}
	return (0);
}
