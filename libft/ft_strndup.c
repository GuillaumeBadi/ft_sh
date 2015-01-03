/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:17:56 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:17:58 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strndup(char const *s, size_t len)
{
	char			*dest;

	dest = (char *)malloc(sizeof(char) * len + 1);
	dest = ft_strncpy(dest, s, len);
	return (dest);
}
