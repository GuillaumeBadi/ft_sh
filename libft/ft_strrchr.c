/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbadi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:18:37 by gbadi             #+#    #+#             */
/*   Updated: 2014/11/10 15:18:39 by gbadi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char			*ft_strrchr(char const *s, int c)
{
	char		*save;
	char		*dest;

	save = NULL;
	dest = (char *)s;
	if (!s)
		return (0);
	while (*dest)
	{
		if (*dest == c)
			save = dest;
		dest++;
	}
	return (save);
}
