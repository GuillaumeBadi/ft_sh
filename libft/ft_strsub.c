/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:18:49 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/26 04:09:15 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;

	i = 0;
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (len--)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
