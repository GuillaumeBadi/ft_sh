/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:17:48 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:17:50 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strncpy(char *dest, char const *src, size_t len)
{
	int			i;

	i = 0;
	while (src[i] && len)
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	return (dest);
}
