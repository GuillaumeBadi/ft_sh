/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:16:31 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:16:31 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, char const *src, size_t len)
{
	size_t		lendst;
	size_t		lensrc;
	size_t		i;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	if (len < lendst)
		return (lensrc + len);
	while (src[i] && lendst + i + 1 < len)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
