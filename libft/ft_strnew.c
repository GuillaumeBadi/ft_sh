/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:18:09 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:18:24 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strnew(size_t size)
{
	char		*dest;

	dest = (char *)malloc(sizeof(char) * size + 1);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, size + 1);
	return (dest);
}
