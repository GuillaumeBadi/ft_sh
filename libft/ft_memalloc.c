/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:12:53 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:12:56 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memalloc(size_t len)
{
	void			*dest;

	dest = (void *)malloc(len);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, len);
	return (dest);
}
