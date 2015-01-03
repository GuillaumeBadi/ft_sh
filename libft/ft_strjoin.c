/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:16:23 by gbadi             #+#    #+#             */
/*   Updated: 2014/12/05 17:25:10 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	size_t			size_s1;
	size_t			size_s2;
	int				i;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	dest = (char *)malloc(size_s1 + size_s2 + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (size_s1--)
		dest[i++] = *s1++;
	while (size_s2--)
		dest[i++] = *s2++;
	dest[i] = 0;
	return (dest);
}
