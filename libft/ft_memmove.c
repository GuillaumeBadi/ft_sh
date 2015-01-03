/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:13:58 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:13:59 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_memmove(void *s1, const void *s2, size_t len)
{
	void		*cpy;

	cpy = (void *)malloc(len);
	ft_memcpy(cpy, s2, len);
	ft_memcpy(s1, cpy, len);
	free(cpy);
	return (s1);
}
