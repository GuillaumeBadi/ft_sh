/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:15:59 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/26 04:19:45 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strdup(const char *str)
{
	char		*dest;

	dest = (char *)ft_memalloc(sizeof(char) * ft_strlen(str) + 1);
	ft_strcpy(dest, str);
	return (dest);
}
